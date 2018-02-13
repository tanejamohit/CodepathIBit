struct Position {
    int x, y, moves;
    Position(int x, int y, int moves): x(x), y(y), moves(moves) {}
};

int minMoves(vector<vector<bool> > &visited, int srcX, int srcY, int destX, int destY) {
    queue<Position> nodesToVisit;
    
    nodesToVisit.push(Position(srcX,srcY,0));
    
    int found = false;
    int minSteps = -1;
    
    while(!found && nodesToVisit.size() > 0) {
        // Take out a node
        Position curPosition = nodesToVisit.front();
        nodesToVisit.pop();
        
        // Check if it is a terminating one
        if ((curPosition.x == destX) && (curPosition.y == destY)) { 
            found = true;
            minSteps = curPosition.moves;
            continue;
        }
        // Out of bounds
        if (curPosition.x < 0 || curPosition.y < 0 || curPosition.x >= visited.size() || curPosition.y >= visited[0].size()) { 
            continue; 
        }
        // If we have already visited this
        if (visited[curPosition.x][curPosition.y]) { 
            continue; 
        }
        visited[curPosition.x][curPosition.y] = true;
        nodesToVisit.push(Position(curPosition.x+2, curPosition.y+1, curPosition.moves+1));
        nodesToVisit.push(Position(curPosition.x-2, curPosition.y+1, curPosition.moves+1));
        nodesToVisit.push(Position(curPosition.x+2, curPosition.y-1, curPosition.moves+1));
        nodesToVisit.push(Position(curPosition.x-2, curPosition.y-1, curPosition.moves+1));
        nodesToVisit.push(Position(curPosition.x+1, curPosition.y+2, curPosition.moves+1));
        nodesToVisit.push(Position(curPosition.x-1, curPosition.y+2, curPosition.moves+1));
        nodesToVisit.push(Position(curPosition.x+1, curPosition.y-2, curPosition.moves+1));
        nodesToVisit.push(Position(curPosition.x-1, curPosition.y-2, curPosition.moves+1));
    }
    
    return minSteps;
}
int Solution::knight(int N, int M, int x1, int y1, int x2, int y2) {
    if (M<=0 || N<=0) { return -1; }
    
    vector<vector<bool> > visited(N, vector<bool>(M, false));
    return minMoves(visited, x1-1, y1-1, x2-1, y2-1);

}
