struct GraphNode {
    vector<GraphNode*> adjacentNodes;
    string value;
    bool visited;
    int minimumDistance;
    
    GraphNode(string val) {
        this->value = val;
        visited = false;
        minimumDistance = 100000;
    }
};

int stepDistance(string a, string b) {
    if (a.size() != b.size()) { return INT_MAX; }
    int stepDistance = 0;
    
    for (int i = 0; i < a.size(); i++) {
        if (a[i]!=b[i]) {
            stepDistance++;
        }
    }
    return stepDistance;
}

std::unordered_map<string, GraphNode*> nodeMapping;

// Create the graph from dictionaries, and return the node pointing to start
GraphNode* createGraph(string start, string end, vector<string> listOfWords) {
    GraphNode* rootNode = new GraphNode(start);
    nodeMapping.clear();
    nodeMapping[start] = rootNode;
    //cout<<"Creating graph"<<endl;
    listOfWords.insert(listOfWords.begin(), start);
    listOfWords.push_back(end);
    
    for(int i = 0; i<listOfWords.size(); i++) {
        for (int j = i+1; j<listOfWords.size(); j++) {
            if (stepDistance(listOfWords[i], listOfWords[j]) == 1) {
                GraphNode* nodeI;
                GraphNode* nodeJ;
                if(nodeMapping.find(listOfWords[i]) == nodeMapping.end()) {
                    nodeMapping[listOfWords[i]] = new GraphNode(listOfWords[i]);
                }
                if(nodeMapping.find(listOfWords[j]) == nodeMapping.end()) {
                    nodeMapping[listOfWords[j]] = new GraphNode(listOfWords[j]);
                }
                nodeI = nodeMapping[listOfWords[i]];
                nodeJ = nodeMapping[listOfWords[j]];
                
                nodeI->adjacentNodes.push_back(nodeJ);
                nodeJ->adjacentNodes.push_back(nodeI);
            }
        }
    }
    
    return rootNode;
}

int minDistance(GraphNode* start, string end) {
    if (start == NULL) {
        return INT_MAX;
    }
    if (start->value == end) { 
        return 0; 
    }
    if (start->visited) {
        return start->minimumDistance;
    }
    //cout<<"Getting min distance from "<<start->value<<endl;
    start->visited = true;
    for(int i = 0; i < start->adjacentNodes.size(); i++) {
        GraphNode* adjacentNode = start->adjacentNodes[i];
        start->minimumDistance = min(start->minimumDistance, minDistance(adjacentNode, end)+1);
    }
    //cout<<"Min distance from "<<start->value<<" = "<<start->minimumDistance<<endl;
    return start->minimumDistance;
}

int Solution::ladderLength(string start, string end, vector<string> &dictV) {
    GraphNode* root = createGraph(start, end, dictV);
    int minimumDistance = minDistance(root, end);
    
    if (minimumDistance == 100000) {
        return 0;
    }
    return minimumDistance+1;
}
