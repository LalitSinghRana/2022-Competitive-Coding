class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> subsets(vector<int>& nums) {
        ans.clear();
        rec(0, nums, {});
        return ans;
    }
    
    void rec(int i, vector<int>& nums, vector<int> arr) {
        if(i >= nums.size()) {
            ans.push_back(arr);
            return;
        }
        rec(i+1, nums, arr);
        
        arr.push_back(nums[i]);
        rec(i+1, nums, arr);
    }
};
