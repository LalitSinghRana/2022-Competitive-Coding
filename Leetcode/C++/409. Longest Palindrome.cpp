class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> m;
        for(auto c : s) m[c]++;
        
        int cnt = 0;
        bool f = 0;
        for(auto [k,v] : m) {
            if(v%2) f = 1;
            cnt += v/2;
        }
        
        cnt *= 2;
        
        return f ? cnt + 1 : cnt;
    }
};
