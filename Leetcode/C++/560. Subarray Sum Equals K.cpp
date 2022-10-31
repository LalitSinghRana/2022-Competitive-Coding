class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> um;
        um[0]++;
        
        int cur = 0, ans = 0;
        for(auto x : nums) {
            cur += x;
            if(um.find(cur-k) != um.end()) {
                ans += um[cur-k];
            }
            um[cur]++;
        }
        
        return ans;
    }
};
