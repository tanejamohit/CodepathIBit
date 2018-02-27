bool isMatchHelper(const string &A, int aPos, const string &B, int bPos, vector<vector<bool>> &isMatchAtPositions) {
    //cout<<"Comparing "<<A[aPos]<<" with "<<B[bPos]<<endl;
    bool isPossible = false;
    if (aPos >= A.size() && bPos >= B.size()) {
        return true;
    }
    else if (aPos >= A.size()) {
        bool skippable = true;
        while (bPos < B.size()) {
            if (B[bPos] == '*') {
                skippable = skippable&true;
            }
            else {
                skippable = skippable&false;
            }
            bPos++;
        }
        return skippable;
    }
    else if (bPos >= B.size()) {
        return false;
    }
    
    if (!isMatchAtPositions[aPos][bPos]) {
        return isMatchAtPositions[aPos][bPos];
    }
    
    if (A[aPos] == B[bPos]) {
        isPossible = isMatchHelper(A, aPos+1, B, bPos+1, isMatchAtPositions);
    }
    else {
        if (B[bPos] == '?') {
            isPossible = isMatchHelper(A, aPos+1, B, bPos+1, isMatchAtPositions);
        }
        else if (B[bPos] == '*') {
            isPossible = isMatchHelper(A, aPos+1, B, bPos+1, isMatchAtPositions) ||
                            isMatchHelper(A, aPos+1, B, bPos, isMatchAtPositions) ||
                            isMatchHelper(A, aPos, B, bPos+1, isMatchAtPositions);
        }
    }
    
    isMatchAtPositions[aPos][bPos] = isPossible;
    return isPossible;
    
}
int Solution::isMatch(const string A, const string B) {
    vector<vector<bool>> isMatchAtPositions(A.size(), vector<bool>(B.size(), true));
    return isMatchHelper(A, 0, B, 0, isMatchAtPositions);
}
