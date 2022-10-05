class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int mx = nums[0], cur = nums[0];
        
        for(int i=1; i<nums.size(); i++) {
            cur += nums[i];
            if(cur <= nums[i]) cur = nums[i];
            if(cur > mx) mx = cur;
        }
        
        return mx;
    }
};
