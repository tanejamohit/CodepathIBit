int Solution::solve(vector<vector<int> > &A) {
    if (A.size() == 0) {
        return 0;
    }
    vector<vector<int>> resultMatrix (A.size(), vector<int>(A[0].size(), 0));

    int count = 0;
    for (int i = 0; i < A.size(); i++) {
        for (int j = 0; j < A[0].size(); j++) {
            int sum = 0;
            // sum = resultMatrix[i-1][j] + resultMatrix[i][j-1] - resultMatrix[i-1][j-1] + A[i][j]
            if (i > 0) {
                sum += resultMatrix[i-1][j];
            }
            if (j > 0) {
                sum += resultMatrix[i][j-1];
            } 
            if (i > 0 && j > 0) {
                sum -= resultMatrix[i-1][j-1];
            }
            sum += A[i][j];
            resultMatrix[i][j] = sum;
            //cout<<"Sum ["<<i<<"]["<<j<<"] = "<<sum<<endl;
        }
    }
    
    for (int sRow = 0; sRow < A.size(); sRow++) {
        for (int sCol = 0; sCol < A[0].size(); sCol++) {
            for (int eRow = sRow; eRow < A.size(); eRow++) {
                for (int eCol = sCol; eCol < A[0].size(); eCol++) {
                    int subMatrixSum = resultMatrix[eRow][eCol];
                    
                    if (sRow > 0) {
                        subMatrixSum -= resultMatrix[sRow-1][eCol];
                    }
                    if (sCol > 0) {
                        subMatrixSum -= resultMatrix[eRow][sCol-1];
                    }
                    if (sRow > 0 && sCol > 0) {
                        subMatrixSum += resultMatrix[sRow-1][sCol-1];
                    }
                    if (subMatrixSum == 0) {
                        count++;
                    }
                    //cout<<"Sum from ["<<sRow<<"]["<<sCol<<"] to ["<<eRow<<"]["<<eCol<<"] = "<<subMatrixSum<<endl;
                }
            }
        }
    }

    return count;
}
