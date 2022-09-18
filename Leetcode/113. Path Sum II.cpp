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
    vector<vector<int>> ans;
    vector<int> cur;
    int tar = 0, sum = 0;
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        tar = targetSum;
        dfs(root);
        return ans;
    }
    
    void dfs(TreeNode* r) {
        if(!r) return;
        
        sum += r->val;
        cur.push_back(r->val);
        if(sum == tar && !r->left && !r->right) ans.push_back(cur);
        
        dfs(r->left);
        dfs(r->right);
        
        sum -= r->val;
        cur.pop_back(); 
    }
};
