int Solution::findMinXor(vector<int> &A) {
    int minValue = INT_MAX;
    sort(A.begin(), A.end());
    
    for (int i = 0; i < A.size()-1; i++) {
        minValue = min(minValue, A[i]^A[i+1]);
    }
    
    return minValue;
}
