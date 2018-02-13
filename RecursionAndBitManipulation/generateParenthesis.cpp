void generateParenthesisRecursively(string currentString, int parenthesisAvailable, int parenthesisOpen, vector<string> &result) {
    if (parenthesisAvailable == 0 && parenthesisOpen == 0) {
        result.push_back(currentString);
    }
    
    if (parenthesisAvailable > 0) {
        generateParenthesisRecursively(currentString+"(", parenthesisAvailable-1, parenthesisOpen+1, result);
    }
    
    if (parenthesisOpen > 0) {
        generateParenthesisRecursively(currentString+")", parenthesisAvailable, parenthesisOpen-1, result);
    }
}

vector<string> Solution::generateParenthesis(int A) {
    vector<string> result;
    int parenthesisAvailable = A;
    int parenthesisOpen = 0;
    generateParenthesisRecursively("", parenthesisAvailable, parenthesisOpen, result);
    return result;
}
