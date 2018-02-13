// E: Edge of the board
// P: Possibly an X

char getCharAt(const vector<vector<char> > &A, int i, int j) {
    if (i<0 || i>=A.size()) { return 'E'; }
    if (A.size()==0 || j<0 || j>=A[0].size()) { return 'E'; }
    return A[i][j];
}


void traverseGraph(const vector<vector<char> > &graph, int i, int j, vector<vector<bool> > &traversed) {
    //cout<<"Traversing "<<i<<" "<<j<<endl;
    traversed[i][j] = true;
    if((getCharAt(graph,i-1,j) == 'O') && (!traversed[i-1][j])) {
        traverseGraph(graph, i-1, j, traversed);
    }
    if((getCharAt(graph,i+1,j) == 'O') && (!traversed[i+1][j])) {
        traverseGraph(graph, i+1, j, traversed);
    }
    if((getCharAt(graph,i,j-1) == 'O') && (!traversed[i][j-1])) {
        traverseGraph(graph, i, j-1, traversed);
    }
    if((getCharAt(graph,i,j+1) == 'O') && (!traversed[i][j+1])) {
        traverseGraph(graph, i, j+1, traversed);
    }
}

void Solution::solve(vector<vector<char> > &A) {
    if (A.size() == 0) { return; }
    
    vector<vector<bool> > traversed(A.size(), vector<bool>(A[0].size(), false));
    int i, j;
    
    // Traverse all the edges of the board
    for (j = 0; j < A[0].size(); j++) {
        if (A[0][j] == 'O') {
            traverseGraph(A, 0, j, traversed);
        }
    }
    for (j = 0; j < A[0].size(); j++) {
        if (A[A.size()-1][j] == 'O') {
            traverseGraph(A, A.size()-1, j, traversed);
        }
    }
    for (i = 0; i < A.size(); i++) {
        if (A[i][0] == 'O') {
            traverseGraph(A, i, 0, traversed);
        }
    }
    for (i = 0; i < A.size(); i++) {
        if (A[i][A[0].size()-1] == 'O') {
            traverseGraph(A, i, A[0].size()-1, traversed);
        }
    }
    
    // Mark all the 'O's not visitied as X
    for (i = 0; i < A.size(); i++) {
        for (j = 0; j < A[0].size(); j++) {
            if(A[i][j] == 'O' && !traversed[i][j]) {
                A[i][j] = 'X';
            }
        }
    }
    
}
