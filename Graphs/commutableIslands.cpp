struct Island {
    int id;
    int costToReach;
    Island(int id, int costToReach): costToReach(costToReach), id(id) {} 
};

struct comparator {
 bool operator()(Island i, Island j) {
 return i.costToReach > j.costToReach;
 }
};

int Solution::solve(int A, vector<vector<int> > &B) {
    vector<unordered_map<int, int>> bridgeConnections(A, unordered_map<int, int>());
    unordered_set<int> islandsConnected;
    priority_queue<Island, vector<Island>, comparator> minHeap;
    int totalCost = 0;
    
    vector<int> costToReachIsland(A, INT_MAX);
    
    for (int i = 0; i < B.size(); i++) {
        int island1 = B[i][0]-1;
        int island2 = B[i][1]-1;
        int cost = B[i][2];
        //cout<<"Cost to go from "<<island1<<" to "<<island2<<" = "<<cost<<endl;
        bridgeConnections[island1][island2] = cost;
        bridgeConnections[island2][island1] = cost;
    }
    
    
    Island first = Island(0, 0);
    
    minHeap.push(first);
    
    while (islandsConnected.size() < A) {
        // Take the top out from minHeap
        Island currentIsland = minHeap.top();
        minHeap.pop();
        if (islandsConnected.find(currentIsland.id) == islandsConnected.end()) {
            totalCost += currentIsland.costToReach;
            islandsConnected.insert(currentIsland.id);
            
            //cout<<"Adding "<<currentIsland.id<<" for cost "<<currentIsland.costToReach<<endl;
            // Push all neighbors of the current
            for (auto itr = bridgeConnections[currentIsland.id].begin(); itr != bridgeConnections[currentIsland.id].end(); itr++) {
                if (islandsConnected.find(itr->first) == islandsConnected.end()) {
                    minHeap.push(Island(itr->first, itr->second));
                }
            }
        }
    }
    
    return totalCost;
}
