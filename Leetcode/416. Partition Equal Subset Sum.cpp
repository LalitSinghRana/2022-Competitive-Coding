class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(auto a : nums) sum += a;
        
        if(sum%2) return false;
        
        return subset(nums, sum/2);
    }
    
    bool subset(vector<int>& nums, int t) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<bool>> dp(n+1, vector<bool>(t+1));
        
        for(auto& arr : dp) arr[0] = true;
        
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=t; j++) {
                if(j < nums[i-1]) dp[i][j] = dp[i-1][j];
                else if(i!=0) dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i-1]];
            }
        }
        
        return dp[n][t];
    }
};
