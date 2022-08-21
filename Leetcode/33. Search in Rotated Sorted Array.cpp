class Solution {
public:
    int search(vector<int>& nums, int t) {
        int l = 0, r = nums.size()-1;
        
        while(l <= r) {
            int m = (l+r)/2;
            if(nums[m] == t) return m;
            else if(nums[l] <= nums[m]) {
                if(t >= nums[l] && t < nums[m]) r = m-1;
                else l = m+1;
            } else {
                if(t > nums[m] && t <= nums[r]) l = m+1;
                else r = m-1;
            }
        }
        
        return -1;
    }
};
