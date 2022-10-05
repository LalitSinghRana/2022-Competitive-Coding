class Solution {
public:
    vector<vector<vector<int>>> g;
    vector<int> cntArr;
    int tar;
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        g.resize(n);
        cntArr.resize(n);
        tar = distanceThreshold;
        
        for(auto& a : edges) {
            g[a[0]].push_back({a[1],a[2]});
            g[a[1]].push_back({a[0],a[2]});
        }
        
        for(int i=0; i<n; i++) helper(i);
        
        int mn = cntArr[0];
        int ans = 0;
        for(int i=0; i<n; i++) {
            if(cntArr[i] <= mn) {
                mn = cntArr[i];
                ans = i;
            }
        }
        
        return ans;
    }
    
    void helper(int src) {
        vector<int> vis(cntArr.size());
        priority_queue<pair<int,int>> pq;
        pq.push({0,src});
        int cnt = -1;
        
        while(!pq.empty()) {
            auto [d,i] = pq.top();
            pq.pop();
            
            if(vis[i]) continue;
            vis[i] = 1;
            cnt++;
            
            for(auto& a : g[i]) {
                if(a[1]-d <= tar && !vis[a[0]]) pq.push({-a[1]+d, a[0]});
            }
        }
        
        cntArr[src] = cnt;
    }
};
