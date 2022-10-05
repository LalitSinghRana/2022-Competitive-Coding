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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return arrayToBST(nums, 0, nums.size()-1);
    }
    
    TreeNode* arrayToBST(vector<int>& nums, int s, int e) {
        if(e < s) return nullptr;
        int m = (s+e)/2;
        
        auto r = new TreeNode(nums[m]);
        r->left = arrayToBST(nums, s, m-1);
        r->right = arrayToBST(nums, m+1, e);
        
        return r;
    }
};
