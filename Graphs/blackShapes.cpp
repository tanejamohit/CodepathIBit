void changeAllBlacks(vector<string> &A, int i, int j) {
    if (i >= 0 && i < A.size() && j >= 0 && j < A[i].size() && A[i][j] == 'X') {
        A[i][j] = 'a';
        changeAllBlacks(A, i-1, j);
        changeAllBlacks(A, i+1, j);
        changeAllBlacks(A, i, j-1);
        changeAllBlacks(A, i, j+1);
    }
}

int Solution::black(vector<string> &A) {
    int numBlackShapes = 0;
    for (int i = 0; i <A.size(); i++) {
        for (int j = 0; j <A[i].size(); j++) {
            if(A[i][j] == 'X') {
                numBlackShapes++;
                //cout<<"Changing all from: "<<i<<" "<<j<<endl;
                changeAllBlacks(A, i, j);
            }
        }
    }
    return numBlackShapes;
}
