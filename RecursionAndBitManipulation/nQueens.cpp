struct Position {
    int i; 
    int j;
    Position(int i, int j): i(i), j(j) {}
};

void addQueenPositionsToResult(const vector<Position> &queenPositions, 
                               vector<vector<string>> &result,
                               const int &n) {
    string repeatedDots (n,'.');
    vector<string> board(n, repeatedDots);
    
    for (auto const &position: queenPositions) {
        board[position.i][position.j] = 'Q';
    }
    result.push_back(board);
}

bool checkAndMarkAllPositionsUsed(vector<vector<bool>> &positions, Position pos) {
    //cout<<"Checking position"<<pos.i<<" "<<pos.j<<endl;
    int i, j;
    // Mark row, column and diagonals
    for (j = pos.j; j < positions[pos.i].size(); j++) {
        positions[pos.i][j] = false;
    }
    for (i = pos.i; i < positions.size(); i++) {
        positions[i][pos.j] = false;
    }
    // Diag down
    for (i = pos.i, j = pos.j; i < positions.size() && j < positions[0].size(); i++, j++) {
            positions[i][j] = false;
    }
    // Diag up
    for (i = pos.i, j = pos.j; i >= 0 && j < positions[0].size(); i--, j++) {
            positions[i][j] = false;
    }

    return true;
}

void findQueenPositions (vector<Position> queenPositions, 
                        int curColumn, 
                        vector<vector<bool>> positionsAvailable, 
                        vector<vector<string>> &result) {
    //cout<<"Column = "<<curColumn<<endl;
    if (curColumn == positionsAvailable.size()) {
        // Add queen positions to result
        //cout<<"Adding to result"<<endl;
        addQueenPositionsToResult(queenPositions, result, positionsAvailable.size());
        return;
    }
    
    // Iterate over all the possible rows for this column
    for(int i = 0; i < positionsAvailable.size(); i++) {
        if (positionsAvailable[i][curColumn]) {
            vector<vector<bool>> positionsAvailableCopy = positionsAvailable;
            Position pos = Position(i,curColumn);
            if(checkAndMarkAllPositionsUsed(positionsAvailableCopy, pos)) {
                //cout<<"Recursing"<<endl;
                vector<Position> queenPositionsCopy = queenPositions;
                queenPositionsCopy.push_back(pos);
                findQueenPositions(queenPositionsCopy, curColumn+1, positionsAvailableCopy, result);
            }
        }
    }
}

vector<vector<string> > Solution::solveNQueens(int n) {
    vector<vector<string >> result;
    vector<Position> queenPositions;
    vector<vector<bool> > positionsAvailable(n, vector<bool>(n,true));

    findQueenPositions(queenPositions, 0, positionsAvailable, result);
    
    return result;
}
