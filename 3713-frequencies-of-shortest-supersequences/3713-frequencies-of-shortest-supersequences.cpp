class Solution {
public:
    vector<vector<int>> supersequences(vector<string>& words) {
        // 1) Gather all unique letters
        unordered_set<char> letterSet;
        for (auto &w : words) {
            letterSet.insert(w[0]);
            letterSet.insert(w[1]);
        }
        vector<char> letters(letterSet.begin(), letterSet.end());
        // Sort for consistent ordering (not required, just tidy)
        sort(letters.begin(), letters.end());
        int n = (int)letters.size();
        
        // Map letter->index
        unordered_map<char,int> indexOf;
        for (int i = 0; i < n; i++) {
            indexOf[letters[i]] = i;
        }
        
        // 2) Build adjacency
        vector<vector<int>> adj(n);
        // Track self-loop forced letters
        vector<bool> forcedSelfLoop(n, false);
        
        for (auto &w : words) {
            int x = indexOf[w[0]];
            int y = indexOf[w[1]];
            if (x == y) {
                // "xx" => forced to appear at least twice
                forcedSelfLoop[x] = true;
            } else {
                // x->y
                adj[x].push_back(y);
            }
        }

        // 3) forcedSet = all letters that must have freq=2
        //    We'll "remove" them from the subgraph (since doubling them breaks any cycle they belong to)
        vector<bool> forced(n, false);
        for (int i = 0; i < n; i++) {
            if (forcedSelfLoop[i]) {
                forced[i] = true;
            }
        }

        // Build subgraph of letters that are NOT forced
        // We'll store them in a list 'remain' for convenience
        vector<int> remain;
        for (int i = 0; i < n; i++) {
            if (!forced[i]) {
                remain.push_back(i);
            }
        }
        int r = (int)remain.size(); // number of non-forced letters

        // We'll need adjacency for the subgraph ignoring forced letters
        // so we only keep edges u->v where neither u nor v is forced
        // Actually, it's simpler just to check forced[u] or forced[v] in cycle detection
        // We'll do that check later in "isAcyclic".

        // 4) Enumerate all subsets of 'remain' to find minimal feedback vertex sets
        //    that break all cycles. We'll do a standard cycle-check ignoring forced letters
        //    and ignoring whichever letters are "removed" (doubled) in the subset.
        
        // We'll define a function to test if subgraph is acyclic after removing a subset
        auto isAcyclic = [&](int subsetMask) {
            // subgraph = all letters i not forced[i] and not in subsetMask
            // plus edges among those letters.
            // We'll do a DFS-based cycle check or Kahn's topological sort.
            // Let's do Kahn's approach:
            
            vector<int> inDegree(n, 0);

            // Compute in-degree for edges that remain
            // An edge u->v remains if !forced[u] && !forced[v] 
            // and also if neither u nor v is in the "subset" (for those in remain).
            for (int u = 0; u < n; u++) {
                if (forced[u]) continue; // removed from subgraph
                bool uRemoved = false;
                // figure out if 'u' is in subset
                // if u is in remain, let's find its index in remain to see if the bit is set
                // We'll store an array posInRemain[] for quick lookup
            }
            // Instead of repeated searching, let's precompute a small array that tells for each letter
            // either "posInRemain[u] = -1 if forced or not in remain" or the index in remain.
            vector<int> posInRemain(n, -1);
            {
                for (int i = 0; i < r; i++) {
                    posInRemain[remain[i]] = i;
                }
            }
            
            // Build inDegree
            for (int u = 0; u < n; u++) {
                if (forced[u]) continue; // letter u is "removed"
                // check if u is in subset
                bool uRem = (posInRemain[u] >= 0) && ((subsetMask >> posInRemain[u]) & 1);
                if (uRem) continue; // removed
                // for each edge u->v
                for (int v : adj[u]) {
                    if (forced[v]) continue; // v removed
                    bool vRem = (posInRemain[v] >= 0) && ((subsetMask >> posInRemain[v]) & 1);
                    if (vRem) continue; // v removed
                    // edge remains
                    inDegree[v]++;
                }
            }

            // Kahn's BFS
            queue<int>q;
            // push all vertices with inDegree=0
            // but only those not forced or in subset
            for (int u = 0; u < n; u++) {
                if (forced[u]) continue;
                bool uRem = (posInRemain[u] >= 0) && ((subsetMask >> posInRemain[u]) & 1);
                if (uRem) continue;
                if (inDegree[u] == 0) {
                    q.push(u);
                }
            }

            int countVisited = 0;
            while(!q.empty()){
                int u = q.front(); q.pop();
                countVisited++;
                // for edges u->v still in subgraph, reduce inDegree
                for (int v: adj[u]) {
                    if (forced[v]) continue;
                    bool vRem = (posInRemain[v] >= 0) && ((subsetMask >> posInRemain[v]) & 1);
                    if (vRem) continue;
                    inDegree[v]--;
                    if (inDegree[v] == 0){
                        q.push(v);
                    }
                }
            }

            // The subgraph's vertex count is all letters that are neither forced nor in subset
            int totalActive = 0;
            for (int u = 0; u < n; u++){
                if (forced[u]) continue;
                bool uRem = (posInRemain[u] >= 0) && ((subsetMask >> posInRemain[u]) & 1);
                if (!uRem) {
                    totalActive++;
                }
            }
            // if we visited all active vertices, no cycle
            return (countVisited == totalActive);
        };

        // Now we enumerate all subsets of 'remain' in ascending order of size so we can track minimal cost
        // Let cost(subset) = forcedCount + subset.size()
        // But we want minimal total length = n + # doubled letters. 
        // Actually the total length = sum of freq = n + forcedCount + subset.size() minus something? 
        // Wait, each letter is at least freq=1 => total baseline for all letters is n.
        // forced[i] => freq=2 => +1 for each forced letter
        // subset => freq=2 => +1 for each letter in subset
        // So final length = n + (# forced) + (subset.size()).
        // We'll find the minimal such sum that yields an acyclic subgraph.

        int forcedCount = 0;
        for (int i = 0; i < n; i++){
            if (forced[i]) forcedCount++;
        }
        int bestCost = INT_MAX;
        vector<int> subsetList; // we'll store the sizes of subsets that achieve the best cost
        // We'll first just find bestCost by scanning all subsets
        for (int mask = 0; mask < (1 << r); mask++) {
            int setSize = __builtin_popcount(mask);
            int totalCost = forcedCount + setSize;
            if (totalCost > bestCost) continue; // no need to check
            if (!isAcyclic(mask)) continue;
            // feasible
            if (totalCost < bestCost) {
                bestCost = totalCost;
            }
        }
        // now collect all subsets that match bestCost
        vector<int> validMasks;
        for (int mask = 0; mask < (1 << r); mask++) {
            int setSize = __builtin_popcount(mask);
            int totalCost = forcedCount + setSize;
            if (totalCost == bestCost) {
                if (isAcyclic(mask)) {
                    validMasks.push_back(mask);
                }
            }
        }

        // 5) Build frequency arrays from each valid subset
        // freq[i] = 2 if forced[i] or i in subset, else 1
        // Then embed in 26-length vector
        vector<vector<int>> ans;
        for (int mask: validMasks) {
            vector<int> freq(n, 1);
            for (int i = 0; i < n; i++){
                if (forced[i]) freq[i] = 2; 
            }
            for (int i = 0; i < r; i++){
                if ((mask >> i) & 1) {
                    freq[ remain[i] ] = 2;
                }
            }
            // convert to 26-length
            vector<int> freq26(26,0);
            for (int i = 0; i < n; i++){
                freq26[ letters[i] - 'a' ] = freq[i];
            }
            ans.push_back(freq26);
        }

        return ans;
    }
};