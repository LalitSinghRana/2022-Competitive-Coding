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
    vector<int> pre, in;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        pre = preorder;
        in = inorder;
        return build(0, pre.size() - 1, 0, in.size() - 1);
    }
    
    TreeNode* build(int ps, int pe, int is, int ie) {
        if(ps > pe || is > ie) return nullptr;
        
        auto root = new TreeNode(pre[ps]);
        
        int i=is;
        while(in[i] != pre[ps]) i++;
        
        root->left = build(ps + 1, ps + i - is, is, i - 1);
        root->right = build(ps + i - is + 1, pe, i + 1, ie);
        
        return root;
    }
};
