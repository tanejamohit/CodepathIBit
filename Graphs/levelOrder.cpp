/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<vector<int> > Solution::levelOrder(TreeNode* A) {
    vector<vector<int> > result;
    vector<TreeNode*> curLevel;
    vector<TreeNode*> nextLevel;
    
    curLevel.push_back(A);
    
    while(curLevel.size()>0) {
        vector<int> levelValues;
        for (int i = 0; i < curLevel.size(); i++) {
            levelValues.push_back(curLevel[i]->val);
            
            if (curLevel[i]->left) { 
                nextLevel.push_back(curLevel[i]->left);
            }
            if (curLevel[i]->right) { 
                nextLevel.push_back(curLevel[i]->right);
            }
        }
        result.push_back(levelValues);
        curLevel = nextLevel;
        nextLevel.clear();
    }
    return result;
}
