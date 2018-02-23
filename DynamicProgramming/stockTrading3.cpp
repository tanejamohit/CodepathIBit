int Solution::maxProfit(const vector<int> &A) {
    if (A.size() == 0) { return 0; }
    
    vector<int> profitValues(A.size(),0);

    int maxProfit = 0;
    int minBuyingPrice = INT_MAX;

    for (int i = 0; i < A.size(); i++) {
        maxProfit = max(maxProfit, A[i] - minBuyingPrice);
        //cout<<"Forward mx profit till "<<i<<" = "<<maxProfit<<endl;
        profitValues[i] = maxProfit;
        minBuyingPrice = min(minBuyingPrice, A[i]);
    }
    
    maxProfit = 0;
    int maxSellingPrice = 0;
    for (int i = ((int)A.size())-1; i >= 0; i--) {
        maxProfit = max(maxProfit, maxSellingPrice - A[i]);
        //cout<<"BAckward mx profit till "<<i<<" = "<<maxProfit<<endl;
        profitValues[i] += maxProfit;
        maxSellingPrice = max(maxSellingPrice, A[i]);
    }
    
    int totalMaxProfit = 0;
    for (int i = 0; i < profitValues.size(); i++)
    {
        totalMaxProfit = max(totalMaxProfit, profitValues[i]);
    }
    return totalMaxProfit;
}
