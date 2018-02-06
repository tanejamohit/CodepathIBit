/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 

void findKthElement(TreeNode* root, const int &k, int &count, int &kthValue, bool &found) {
    if (!root || found) {
        return;
    }
    if (count == k && !root->left && !root->right) {
        kthValue = root->val;
        found = true;
    }
    
    findKthElement(root->left, k, count, kthValue, found);
    
    if (!found) {
        count++;
        if (count == k) {
            kthValue = root->val;
            found = true;
            return;
        }
        findKthElement(root->right, k, count, kthValue, found);
    }
}
int Solution::kthsmallest(TreeNode* root, int k) {
    int count = 0; 
    bool found = false;
    int kthValue = 0;
    
    findKthElement(root, k, count, kthValue, found);
    
    if (!found) { return 0; }
    
    return kthValue;
}
