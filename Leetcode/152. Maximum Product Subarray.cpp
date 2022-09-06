class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int mx = nums[0], mn = nums[0], ans = nums[0];
        if(!nums[0]) {
            mx = 1;
            mn = 1;
        }
        
        for(int i=1; i<nums.size(); i++) {
            int t = mx;
            mx = max(max(nums[i]*mx, nums[i]*mn), nums[i]);
            mn = min(min(nums[i]*t, nums[i]*mn), nums[i]);
            ans = max(ans, mx);
                        
            if(!nums[i]) {
                mx = 1;
                mn = 1;
            }
        }
        
        return ans;
    }
};
