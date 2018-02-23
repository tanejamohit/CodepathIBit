vector<int> Solution::solve(int A, int B, int C, int k) {
    //unordered_set<int> resultSet;
    vector<int> result;
    int lastPushedValue = -1;
    
    int posA = 0;
    int posB = 0;
    int posC = 0;
    
    result.push_back(1);

    while(result.size() <= k) {
        int numA = result[posA]*A;
        int numB = result[posB]*B;
        int numC = result[posC]*C;
        
        int minValue;
        if (numA <= numB && numA <= numC) {
            minValue = numA;
            posA++;
        }
        else if (numB <= numA && numB <= numC) {
            minValue = numB;
            posB++;
        }
        else {
            minValue = numC;
            posC++;
        }
        
        if (minValue > lastPushedValue) {
            result.push_back(minValue);
            lastPushedValue = minValue;
        }
    }
    
    result.erase(result.begin());
    return result;
}
