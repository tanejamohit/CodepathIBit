bool checkRowValid(const vector<string> &A, int row) {
    vector<bool> numbersEncountered(9, false);
    for (int i = 0; i < A[row].size(); i++) {
        if (A[row][i] != '.') {
            int num = (int)(A[row][i] - '0');
            if (numbersEncountered[num]) {
                return false;
            }
            else {
                numbersEncountered[num] = true;
            }
        }
    }
    return true;
}

bool checkColumnValid(const vector<string> &A, int column) {
    vector<bool> numbersEncountered(9, false);
    for (int i = 0; i < A.size(); i++) {
        if (A[i][column] != '.') {
            int num = (int)(A[i][column] - '0');
            if (numbersEncountered[num]) {
                return false;
            }
            else {
                numbersEncountered[num] = true;
            }
        }
    }
    return true;
}

bool checkSubMatrixValid(const vector<string> &A, int startRow, int startColumn) {
    vector<bool> numbersEncountered(9, false);
    for (int i = startRow; i < startRow+3; i++ ) {
        for (int j = startColumn; j < startColumn+3; j++) {
            if (A[i][j] != '.') {
                int num = (int)(A[i][j] - '0');
                if (numbersEncountered[num]) {
                    return false;
                }
                else {
                    numbersEncountered[num] = true;
                }
            }
        }
    }
    return true;
}

int Solution::isValidSudoku(const vector<string> &A) {
    if (A.size() == 0 || A.size()!= A[0].size()) { return 0; }
    
    // Check rows and columns
    for (int i = 0; i < A.size(); i++) {
        if (!checkRowValid(A, i) || !checkColumnValid(A, i)) {
            return 0;
        }
    }
    // Check sub matrices
    for (int i = 0; i < A.size() -1; i += 3 ) {
        for (int j = 0; j <A[0].size() -1; j += 3) {
            if(!checkSubMatrixValid(A, i, j)) {
                return 0;
            }
        }
    }
    return 1;
}
