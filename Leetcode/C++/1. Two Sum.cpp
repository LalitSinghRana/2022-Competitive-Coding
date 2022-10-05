class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int t) {
        unordered_map<int,int> m;
        vector<int> ans;
        for(int i=0; i<nums.size(); i++) {
            int x = t-nums[i];
            if(m.find(x) != m.end()) {
                ans = {m[x],i};
                break;
            }
            m.insert({nums[i],i});
        }
        return ans;
    }
};
