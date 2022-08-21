class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, vector<string>> g;
        unordered_map<string, string> m;
        unordered_set<string> v;
        
        for(auto List : accounts) {
            m[List[1]] = List[0];
            if(g.find(List[1]) == g.end()) g[List[1]] = {};
            for(int i=2; i<List.size(); i++) {
                g[List[1]].push_back(List[i]);
                g[List[i]].push_back(List[1]);
                m[List[i]] = List[0];
            }
        }
        
        vector<vector<string>> ans;
        
        for(auto [k,vl] : g) {
            vector<string> arr;
            dfs(k, g, v, arr);
            if(!arr.empty()) ans.push_back(arr);
        }
        
        for(auto& arr : ans) {
            sort(arr.begin(), arr.end());
            arr.insert(arr.begin(), m[arr[0]]);
        }
        
        return ans;
    }
    
    void dfs(string k, unordered_map<string, vector<string>> &g, unordered_set<string> &v, vector<string> &arr) {
        if(v.find(k) != v.end()) return;
        v.insert(k);
        arr.push_back(k);
        
        for(auto s : g[k]) dfs(s, g, v, arr);
    }
};
