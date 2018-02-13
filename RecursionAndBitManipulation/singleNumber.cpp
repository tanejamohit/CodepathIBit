int Solution::singleNumber(const vector<int> &A) {
    if (A.size() < 1) { return -1; }
    int result = A[0];
    for (int i =1; i < A.size(); i++) {
        result = result^A[i];
    }
    return result;
}
