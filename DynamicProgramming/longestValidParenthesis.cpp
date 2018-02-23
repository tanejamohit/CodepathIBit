int Solution::longestValidParentheses(string A) {
    vector<int> openingBracesPositions;
    int startPosition = -1;
    int maxSize = 0;
    
    for (int i = 0; i < A.size(); i++) {
        if (A[i] == '(') {
            if ((openingBracesPositions.size() == 0) && (startPosition == -1)) {
                startPosition = i;
                //cout<<"Start pos="<<i<<endl;
            }
            openingBracesPositions.push_back(i);
        }
        else if (A[i] == ')') {
            if (openingBracesPositions.size() == 0) {
                startPosition = -1;
            }
            else {
                // We should check for max in these situations
                openingBracesPositions.pop_back();
                int lastBracePosition = openingBracesPositions.back() + 1;
                // If this is the last brace then lastBracePosition should be startPosition
                if (openingBracesPositions.size() == 0) {
                    lastBracePosition = startPosition;
                }
                maxSize = max(maxSize, i - lastBracePosition + 1);
                //cout<<"MaxSize at i:"<<i<<"="<<maxSize<<endl;
            }
        }
    }
    return maxSize;
}
