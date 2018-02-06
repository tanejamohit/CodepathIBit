/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
void SearchForNodes(TreeNode* root, const int &A, const int &B, bool &foundA, bool& foundB, int &commonAncestor) {
    if (!root) { return; }
    int initialFound = (foundA?1:0) + (foundB?1:0);
    if (A == B && root->val == A) {
        foundA = true;
        foundB = true;
        commonAncestor = root->val;
        return;
    }
    if(root->val == A) { 
        foundA = true;
    }
    if(root->val == B) { 
        foundB = true;
    }

    int numFoundBeforeLeftSearch = (foundA?1:0) + (foundB?1:0);
    SearchForNodes(root->left, A, B, foundA, foundB, commonAncestor);
    
    int foundAfterLeftSearch = (foundA?1:0) + (foundB?1:0);

    if ((initialFound == 0) && 
        (numFoundBeforeLeftSearch == 1) && 
        (foundAfterLeftSearch == 2)) { 
        commonAncestor = root->val;
        return; 
    }
    else if (foundAfterLeftSearch == 2) {
        return;
    }
    
    SearchForNodes(root->right, A, B, foundA, foundB, commonAncestor);
    
    int foundAfterRightSearch = (foundA?1:0) + (foundB?1:0);
    if ((initialFound == 0) && (foundAfterLeftSearch == 1) && (foundAfterRightSearch == 2)) { 
        commonAncestor = root->val; 
    }
}
int Solution::lca(TreeNode* root, int A, int B) {
    bool foundA = false;
    bool foundB = false;
    int commonAncestor = -1;
    SearchForNodes(root, A, B, foundA, foundB, commonAncestor);
    return commonAncestor;
}
