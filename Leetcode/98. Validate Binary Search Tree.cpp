/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return isValid(root, pow(-2, 31)-1, pow(2, 31));
    }
    
    bool isValid(TreeNode* r, long mn, long mx) {
        if(!r) return true;
        if(r->val <= mn || r->val >= mx) return false;
        // cout<<r->val<<endl;
        
        return isValid(r->left, mn, r->val) && isValid(r->right, r->val, mx);
    }
};
