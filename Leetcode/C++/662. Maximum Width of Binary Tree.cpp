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
    int mx = 0;
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        
        int mx = 0;
        queue<pair<TreeNode*, long long int>> q;
        q.push({root, 0});
        
        while(!q.empty()) {
            int size = q.size();
            int s = q.front().second, e = q.back().second;
            
            mx = max(mx, e-s+1);
            
            while(size--) {
                auto [p, x] = q.front();
                q.pop();
                int idx = x - s;
                
                if(p->left) q.push({p->left, (long long)2*idx + 1});
                if(p->right) q.push({p->right, (long long)2*idx + 2});
            }
        }
        
        return mx;
    }
};
