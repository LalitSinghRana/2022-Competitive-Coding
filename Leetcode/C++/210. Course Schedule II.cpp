class Solution {
public:
    vector<vector<int>> g;
    
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        g.resize(n);
        for(auto a : prerequisites) g[a[1]].push_back(a[0]);
        
        if(detectCycle()) return {};
        return topologicalSort();
    }
    
    vector<int> topologicalSort() {
        int n = g.size();
        vector<bool> vis(n);
        stack<int> s;
        
        for(int i=0; i<n; i++) dfs2(i, s, vis);
        
        vector<int> res;
        while(!s.empty()) {
            res.push_back(s.top());
            s.pop();
        }
        
        return res;
    }
    
    void dfs2(int k, stack<int> &s, vector<bool> &vis) {
        if(vis[k]) return;
        vis[k] = 1;
        for(auto x : g[k]) dfs2(x, s, vis);
        s.push(k);
    }
    
    bool detectCycle() {
        int n = g.size();
        vector<bool> vis(n);
        for(int i=0; i<n; i++) if(!vis[i] &&  dfs(i, vis)) return true;
        return false;
    }
    
    bool dfs(int k, vector<bool> &vis) {
        if(vis[k]) return true;
        vis[k] = 1;
        
        for(auto x : g[k]) if(dfs(x, vis)) return true;
        
        vis[k] = 0;
        
        return false;
    }
};
