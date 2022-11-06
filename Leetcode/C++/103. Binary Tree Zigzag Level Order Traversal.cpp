class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        if(root) q.push(root);
        vector<vector<int>> ans;
        auto flag = false;
        
        while(!q.empty()) {
            auto size = q.size();
            vector<int> v = {};
            
            while(size--) {
                auto x = q.front();
                q.pop();
                v.push_back(x->val);
                if(x->left) q.push(x->left);
                if(x->right) q.push(x->right);
            }
            
            if(flag) reverse(v.begin(), v.end());
            ans.push_back(v);
            flag = !flag;
        }
        
        return ans;
    }
};
