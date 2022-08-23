class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<vector<pair<int,double>>> g(n);
        vector<bool> v(n);
        priority_queue<pair<double, int>> q;
        
        for(int i=0; i<edges.size(); i++) {
            g[edges[i][0]].push_back({edges[i][1], succProb[i]});
            g[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }
        
        q.push({1, start});
        
        while(!q.empty()) {
            auto [pro, k] = q.top();
            q.pop();            
            if(k == end) return pro;
            if(v[k]) continue;
            
            v[k] = 1;
            
            for(int i=0; i<g[k].size(); i++) { 
                if(g[k][i].second && !v[g[k][i].first]) {
                    q.push({pro*g[k][i].second, g[k][i].first});
                }
            }
        }
        
        return 0;
    }
};
