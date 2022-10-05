class Solution {
public:
    int rob(vector<int>& nums) {
        int in = nums[0], ex = 0;
        for(int i=1; i<nums.size(); i++) {
            int newIn = ex + nums[i];
            ex = max(in, ex);
            in = newIn;
        }
        return max(in, ex);
    }
};
