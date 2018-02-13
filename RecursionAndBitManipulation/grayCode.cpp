void generateGrayCodes(int pos, int maxPos, vector<int> &result) {
    if (pos >= maxPos) { return; }
    for (int i = result.size()-1; i>=0; i--) {
        int newValue = result[i] + (1<<pos);
        result.push_back(newValue);
    }
    generateGrayCodes(pos+1, maxPos, result);
}
vector<int> Solution::grayCode(int A) {
    vector<int> result;
    result.push_back(0);
    result.push_back(1);
    
    generateGrayCodes(1, A, result);
    //for (int i = 0; i < result.size(); i++) { cout<<result[i]<<endl; }
    return result;
}
