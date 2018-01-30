vector<int> Solution::dNums(vector<int> &A, int B) {
    vector<int> result;
    std::unordered_map<int, int> seen;
    int pos = 0;
    
    while(pos<B) {
        if (seen.find(A[pos]) == seen.end()) { seen[A[pos]] = 0; }
        seen[A[pos]] += 1;
        pos++;
    }
    while(pos<=A.size()) {
        result.push_back(seen.size());
        if (seen[A[pos-B]] == 1) {
            seen.erase(seen.find(A[pos-B]));
        }
        else {
            seen[A[pos-B]] -= 1;
        }
        if (seen.find(A[pos]) == seen.end()) { seen[A[pos]] = 0; }
        seen[A[pos]] += 1;
        pos++;
    }
    return result;
}
