int Solution::lengthOfLongestSubstring(string A) {
    std::unordered_map<char, int> occurences;
    int maxLengthSubString = 0;
    int startPos = 0;
    string longestSubStr;
    
    for (int i = 0; i < A.size(); i++) {
        if (occurences.find(A[i]) != occurences.end()) {
            maxLengthSubString = max(maxLengthSubString, i - startPos);
            startPos = max(startPos, occurences[A[i]] + 1);
        }
        occurences[A[i]] = i;
    }
    maxLengthSubString = max(maxLengthSubString, (int)A.size() - startPos);
    return maxLengthSubString;
}
