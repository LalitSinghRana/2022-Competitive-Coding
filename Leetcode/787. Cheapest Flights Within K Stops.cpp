class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<vector<int>>> g(n);
        for(auto& a : flights) g[a[0]].push_back({a[1],a[2]});
        
        priority_queue<vector<int>> pq;
        vector<int> vis(n, INT_MAX);
        pq.push({0,src,0});
        k++;
        
        while(!pq.empty()) {
            auto b = pq.top();
            pq.pop();
                        
            if(b[1] == dst) return -b[0];
            if(b[2] == k) continue;
            vis[b[1]] = b[2];
            
            for(auto& arr : g[b[1]]) if(vis[arr[0]] > b[2]+1) pq.push({(-arr[1])+b[0], arr[0], b[2]+1});
        }
        
        return -1;
    }
};
