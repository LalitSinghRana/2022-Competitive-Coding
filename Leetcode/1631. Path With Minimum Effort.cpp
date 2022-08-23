class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size(), m = heights[0].size();
        vector<vector<int>> g(n, vector<int>(m, INT_MAX));
        vector<vector<bool>> v(n, vector<bool>(m));
        priority_queue<pair<int, pair<int,int>>> q;
        
        q.push({0, {0,0}});
        
        while(!q.empty()) {
            auto arr = q.top();
            q.pop();
            
            int e = (-1)*arr.first, i = arr.second.first, j = arr.second.second;
            if(v[i][j]) continue;
            
            v[i][j] = 1;
            g[i][j] = e;
            
            if(i == n-1 && j == m-1) return e;
            
            if(i-1 >= 0 && !v[i-1][j]) {
                int ne = -1 * min(g[i-1][j], max(e, abs(heights[i-1][j] - heights[i][j])));
                q.push({ne, {i-1, j}});
            }
            if(i+1 < n && !v[i+1][j]) {
                int ne = -1 * min(g[i+1][j], max(e, abs(heights[i+1][j] - heights[i][j])));
                q.push({ne, {i+1, j}});
            }
            if(j-1 >= 0 && !v[i][j-1]) {
                int ne = -1 * min(g[i][j-1], max(e, abs(heights[i][j-1] - heights[i][j])));
                q.push({ne, {i, j-1}});
            }
            if(j+1 < m && !v[i][j+1]) {
                int ne = -1 * min(g[i][j+1], max(e, abs(heights[i][j+1] - heights[i][j])));
                q.push({ne, {i, j+1}});
            }
        }
        
        return g[n-1][m-1];
    }
};
