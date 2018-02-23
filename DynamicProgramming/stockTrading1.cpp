int Solution::maxProfit(const vector<int> &A) {
    int minBuyingPrice = INT_MAX;
    int maxProfit = 0;
    
    for (int i = 0; i < A.size(); i++) {
        maxProfit = max(maxProfit, A[i] - minBuyingPrice);
        minBuyingPrice = min(minBuyingPrice, A[i]);
    }
    return maxProfit;
}
