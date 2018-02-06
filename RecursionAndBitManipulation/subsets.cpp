void recursivelyCombinate(vector<int> &A, int pos, vector<int> currentSolution, vector<vector<int>> &result) {
    if (pos == A.size()-1) {
       result.push_back(currentSolution);
       currentSolution.push_back(A[pos]);
       result.push_back(currentSolution);
       return;
    }
    
    recursivelyCombinate(A, pos+1, currentSolution, result);
    currentSolution.push_back(A[pos]);
    recursivelyCombinate(A, pos+1, currentSolution, result);
}

bool sortFunctionForVector (vector<int> A, vector<int> B) { 
    for(int i=0; i < A.size(); i++) {
        if (i < B.size()) {
            if (A[i] > B[i]) { return false; }
            else if (A[i] < B[i]) { return true; }
        }
        else {
            return false; // B is greater
        }
    }
    return true;  
    
}

vector<vector<int> > Solution::subsets(vector<int> &A) {
    vector<vector<int>> result;
    if (A.size() == 0) { 
        vector <int> empty;
        result.push_back(empty);
        return result; 
    }
    std::sort(A.begin(), A.end());
    vector<int> currentSolution;
    recursivelyCombinate(A, 0, currentSolution, result);
    std::sort(result.begin(), result.end(), sortFunctionForVector);
    return result;
}
