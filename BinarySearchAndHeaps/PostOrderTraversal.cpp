/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::postorderTraversal(TreeNode* A) {
    vector<int> result;
    stack<TreeNode*> stack;

    if (A) { stack.push(A); }
    
    while(stack.size() > 0) {
        TreeNode* current = stack.top();
        stack.pop();
        if (current->left) { stack.push(current->left); }
        if (current->right) { stack.push(current->right); }
        
        result.push_back(current->val);
    }
    reverse(result.begin(), result.end());
    return result;
}
