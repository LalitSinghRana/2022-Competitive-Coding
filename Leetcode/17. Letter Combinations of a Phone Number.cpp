class Solution {
public:
    vector<string> ans;
    unordered_map<int, vector<char>> m = {
        {2, {'a','b','c'}},
        {3, {'d','e','f'}},
        {4, {'g','h','i'}},
        {5, {'j','k','l'}},
        {6, {'m','n','o'}},
        {7, {'p','q','r','s'}},
        {8, {'t','u','v'}},
        {9, {'w','x','y','z'}}
    };
    
    vector<string> letterCombinations(string digits) {
        ans.clear();
        string s = "";
        dfs(digits, 0, s);
        return ans;
    }
    
    void dfs(string& digits, int k, string& s) {
        if(k >= digits.size() && s != "") {
            ans.push_back(s);
            return;
        }
        
        for(char c : m[digits[k] - '0']) {
            s += c;
            dfs(digits, k+1, s);
            s.pop_back();
        }
    }
};
