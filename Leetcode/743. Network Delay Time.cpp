class Solution {
public:
    vector<vector<pair<int,int>>> g;
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        g.resize(n+1);
        for(auto& a : times) g[a[0]].push_back({a[1],a[2]});
        
        unordered_set<int> vis;
        priority_queue<pair<int,int>> pq;
        
        pq.push({0,k});
        int ans = 0;
        
        while(!pq.empty()) {
            auto [t,s] = pq.top();
            pq.pop();
            
            if(vis.find(s) != vis.end()) continue;
            vis.insert(s);
            t *= -1;
            ans = max(ans,t);
            
            for(auto& [d,t2] : g[s]) {
                pq.push({-1*(t+t2),d});
            }
        }
        
        if(vis.size() != n) return -1;
        
        return ans;
        
    }
};
