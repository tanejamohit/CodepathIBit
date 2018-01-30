vector<int> Solution::searchRange(const vector<int> &A, int B) {
    int start = 0, end = A.size()-1;
    int mid;
    vector<int> result;
    while (start<=end) {
        mid = (start+end)/2;
        if (( mid==0 || A[mid-1] < B) && (A[mid] == B)) { break; }
        if (A[mid] < B) {
            start = mid+1;
        }
        else {
            end = mid-1;
        }
    }
    if (A[mid]==B) {
        result.push_back(mid);
    }
    else {
        result.push_back(-1);
    }
    start = 0; 
    end = A.size()-1;
    while (start<=end) {
        mid = (start+end)/2;
        if (( mid==0 || A[mid+1] > B) && (A[mid] == B)) { break; }
        if (A[mid] > B) {
            end = mid-1;
        }
        else {
            start = mid+1;
        }
    }
    if (A[mid]==B) {
        result.push_back(mid);
    }
    else {
        result.push_back(-1);
    }
    return result;
}
