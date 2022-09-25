class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int> m;
        int sum = 0, mx = 0;
        for(int i=0; i<nums.size(); i++) {
            if(nums[i]) sum++;
            else sum--;
            
            if(sum == 0) mx = max(mx, i+1);
            else if(m.find(sum) != m.end()) {
                mx = max(mx, i - m[sum]);
            } else m[sum] = i;
        }
        
        return mx;
    }
};
