int Solution::cntBits(vector<int> &A) {
    int sum = 0;
    
    if(A.size()==0) { return 0; }
    
    int numBits = sizeof(A[0])*8;
    vector<int> numOnBits(numBits, 0);
    
    for (int i = 0; i < A.size(); i++) {
        for (int j = 0; j < numBits; j++) {
            if(A[i]&(1<<j)) {
                numOnBits[j] += 1;
            }
        }
    }
    
    for (int i = 0; i < numBits; i++) {
        sum += (2*numOnBits[i]*(A.size() - numOnBits[i]))%1000000007;
        sum %= 1000000007;
    }
    return sum;
}
