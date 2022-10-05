class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size()-1;
        
        while(l <= r) {
            if(nums[l] <= nums[r]) return nums[l];
            
            int m = (l+r)/2;
            if(m != 0 && nums[m-1] >= nums[m]) return nums[m];
            else if(nums[l] <= nums[m]) l = m+1;
            else r = m-1;
        }
        
        return 5001;
    }
};
