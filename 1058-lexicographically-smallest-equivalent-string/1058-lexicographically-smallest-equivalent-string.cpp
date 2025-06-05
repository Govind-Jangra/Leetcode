class Solution {
public:
    class DSU{
    public:
        vector<int> size;
        vector<int> parent;
        vector<int> smallest;

        DSU(){
            for(int i=0; i<26; i++){
                parent.push_back(i);
                smallest.push_back(i);
            }

            size.resize(26, 1);
        }

        int getUltimateParent(int u){
            if(parent[u] == u) return u;
            return parent[u] = getUltimateParent(parent[u]);
        }

        void unionNode(int u, int v){
            int ultU = getUltimateParent(u);
            int ultV = getUltimateParent(v);
            if(ultU == ultV) return;

            if(size[ultU] < size[ultV]){
                parent[ultU] = ultV;
                size[ultV] += ultU;
                smallest[ultV] = std::min(smallest[ultV], smallest[ultU]);
            }else{
                parent[ultV] = ultU;
                size[ultU] += ultV;
                smallest[ultU] = std::min(smallest[ultV], smallest[ultU]);
            }
        }

        int getSmallest(int u){
            int ultU = getUltimateParent(u);
            return smallest[ultU];
        }
    };

    string smallestEquivalentString(string s1, string s2, string baseStr) {
        DSU* dsu = new DSU();
        for(int i=0; i<s1.size(); i++){
            dsu->unionNode(s1[i]-'a', s2[i]-'a');
        }

        string ans = "";
        for(int i=0; i<baseStr.size(); i++){
            ans += dsu->getSmallest(baseStr[i]-'a') + 'a';
        }

        return ans;
    }
};