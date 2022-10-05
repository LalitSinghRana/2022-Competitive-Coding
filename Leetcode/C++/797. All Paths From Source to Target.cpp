class Solution {
public:
    deque<int> dq;
    int n;
    vector<vector<int>> ans;
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& g) {
        n = g.size();
        dq.clear();
        ans.clear();
        
        dfs(0, g);
        return ans;
    }
    
    void dfs(int k, vector<vector<int>>& g) {
        dq.push_back(k);
        
        if(k == n-1) {
            auto q = dq;
            vector<int> res;
            while(!q.empty()) {
                res.push_back(q.front());
                q.pop_front();
            }
            ans.push_back(res);
        } else for(auto x : g[k]) dfs(x, g);
        
        dq.pop_back();
    }
};
