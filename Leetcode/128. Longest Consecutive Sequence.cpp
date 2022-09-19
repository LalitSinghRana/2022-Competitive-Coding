class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        for(auto x : nums) s.insert(x);
        
        int mx = 0;
        for(auto x : nums) {
            if(s.find(x-1) == s.end()) {
                int cnt = 1;
                while(s.find(++x) != s.end()) cnt++;
                mx = max(mx, cnt);
            }
        }
        
        return mx;
    }
};
