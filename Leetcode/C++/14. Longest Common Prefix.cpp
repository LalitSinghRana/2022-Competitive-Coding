class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = strs[0];
        for(auto str : strs) {
            int j=0;
            string t;
            while(j<str.size() && j<ans.size()) {
                if(str[j] != ans[j]) break;
                t += ans[j++];
            }
            ans = t;
        }
        return ans;
    }
};
