class Solution {
public:
    int o = 0, c = 0;
    vector<string> ans;
    vector<string> generateParenthesis(int n) {
        gen("", n, 0, 0);
        return ans;
    }
    
    void gen(string s, int n, int o, int c) {
        if(o == n && c == n) {
            ans.push_back(s);
            return;
        }
        if(o < n) gen(s+"(", n, o+1, c);
        if(c < o) gen(s+")", n, o, c+1);
    }
};
