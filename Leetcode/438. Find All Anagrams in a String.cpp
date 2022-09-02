class Solution {
public:
    vector<int> t, m;
    vector<int> findAnagrams(string s, string p) {
        if(p.size() > s.size()) return {};
        
        int n = p.size();
        t.resize(26,0);
        m.resize(26,0);
        for(auto c : p) t[c - 'a']++;
        
        for(int i=0; i<n; i++) m[s[i] - 'a']++;
        
        vector<int> ans;
        if(isAnagram()) ans.push_back(0);
        
        for(int i=n; i<s.size(); i++) {
            m[s[i-n] - 'a']--;
            m[s[i] - 'a']++;
            if(isAnagram()) ans.push_back(i-n+1);
        }
        
        return ans;
    }
    
    bool isAnagram() {
        if(t.size() != m.size()) return 0;
        for(int i=0; i<26; i++) if(m[i] != t[i]) return 0;
        return 1;
    }
};
