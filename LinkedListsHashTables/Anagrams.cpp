string getSortedString(string A) {
    std::unordered_map<char, int> characterFreq;
    string sortedString = "";
    for (int i = 0; i < A.size(); i++) {
        if (characterFreq.find(A[i]) == characterFreq.end()) {
            characterFreq[A[i]] = 0;
        }
        characterFreq[A[i]] += 1;
    }
    for (char x = 'a'; x < 'z'; x++) {
        if (characterFreq.find(x) != characterFreq.end()) {
            string characters(characterFreq[x], x);
            sortedString += characters;
        }
    }
    return sortedString;
}

vector<vector<int> > Solution::anagrams(const vector<string> &A) {
    std::unordered_map<string, vector<int>> sortedStringMapping;
    vector<vector<int> > result;
    
    for (int i =0; i < A.size(); i++) {
        string sortedString = getSortedString(A[i]);
        //cout<<"Sorted string for "<<A[i]<<" is "<<sortedString<<endl;
        sortedStringMapping[sortedString].push_back(i+1);
    }
    
    for (auto it = sortedStringMapping.begin(); it != sortedStringMapping.end(); ++it) {
        result.push_back(it->second);
    }
    
    return result;
}
