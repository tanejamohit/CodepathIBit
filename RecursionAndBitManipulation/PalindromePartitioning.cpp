bool checkPalindrome(string& input, int start, int end) {
    while(start<end) {
        if (input[start] != input[end]) { return false; }
        start++;
        end--;
    }
    return true;
}

void generatePartitions(string& input, int position, vector<string> currentPartition, vector< vector<string>> &allPartitions) {
    if (position >= input.size()) {
        allPartitions.push_back(currentPartition);
        return;
    }
    
    for (int offset = 1; offset <= input.size() - position; offset++) {
        if (checkPalindrome(input, position, position+offset-1)) {
            //cout<<"Position = "<<position<<" offset = "<<offset<<endl;
            vector<string> newPartition = currentPartition;
            newPartition.push_back(input.substr(position, offset));
            generatePartitions(input, position+offset, newPartition, allPartitions);
        }
    }
}
vector<vector<string> > Solution::partition(string A) {
    vector<vector<string>> result;
    vector<string> currentPartition;
    generatePartitions(A, 0, currentPartition, result);
    return result;
}
