int Solution::adjacent(vector<vector<int> > &A) {
    if (A.size() == 0) { return 0; }
    
    int prevSum = 0;
    int prevPrevSum = 0;
    int curSum = 0;
    
    for (int i = 0; i < A[0].size(); i++) {
        curSum = max(max(A[0][i], A[1][i]) + prevPrevSum, prevSum);
        
        prevPrevSum = prevSum;
        prevSum = curSum;
    }
    
    return curSum;
}
