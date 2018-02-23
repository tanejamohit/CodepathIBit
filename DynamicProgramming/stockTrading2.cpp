int Solution::maxProfit(const vector<int> &A) {
    int profit = 0;
    int buyingPrice = INT_MAX;
    
    for (int i = 0; i < A.size(); i++) {
        if (( i > 0 ) && (A[i] < A[i-1]) && (A[i-1] > buyingPrice)) {
            profit += A[i-1] - buyingPrice;
            buyingPrice = INT_MAX;
        }
        if (A[i] < buyingPrice) {
            buyingPrice = A[i];
        }
    }
    
    if (A[A.size()-1] > buyingPrice) {
        profit += A[A.size()-1] - buyingPrice;
    }
    
    return profit;
}
