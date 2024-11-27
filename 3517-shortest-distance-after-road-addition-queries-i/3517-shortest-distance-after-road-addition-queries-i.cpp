class Solution {
    int numNodes;
    vector<vector<int>> adjacencyList;
    vector<int> shortestReach;

public:
    void updateDistance(int currentNode, int currentPathLength) {
        if (shortestReach[currentNode] > currentPathLength) {
            shortestReach[currentNode] = currentPathLength;
            currentPathLength++;
            for (int i = 0; i < adjacencyList[currentNode].size(); i++) {
                updateDistance(adjacencyList[currentNode][i],
                               currentPathLength);
            }
        }
    }

    vector<int> shortestDistanceAfterQueries(int n,vector<vector<int>>& queries) {
        numNodes = n;
        adjacencyList.resize(numNodes);
        shortestReach.resize(numNodes);
        for (int i = 0; i < numNodes; i++) {
            if (i < numNodes - 1)
                adjacencyList[i].push_back(i + 1);
            shortestReach[i] = i;
        }
        vector<int> result(queries.size());
        for (int i = 0; i < queries.size(); i++) {
            auto newRoad = queries[i];
            int newPathLength = shortestReach[newRoad[0]] + 1;
            adjacencyList[newRoad[0]].push_back(newRoad[1]);
            updateDistance(newRoad[1], newPathLength);
            result[i] = shortestReach[numNodes - 1];
        }
        return result;
    }
};