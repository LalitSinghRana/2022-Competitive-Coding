class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        queue<pair<int,int>> q;
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) if(grid[i][j] == 2) q.push({i,j});
        }
        
        int time = -1;
        
        while(!q.empty()) {
            int l = q.size();
            time++;
            
            while(l--) {
                auto [x,y] = q.front();
                q.pop();
                
                if(x-1 >= 0 && grid[x-1][y] == 1) {
                    grid[x-1][y] = 2;
                    q.push({x-1,y});
                }
                if(x+1 < n && grid[x+1][y] == 1) {
                    grid[x+1][y] = 2;
                    q.push({x+1,y});
                }
                if(y-1 >= 0 && grid[x][y-1] == 1) {
                    grid[x][y-1] = 2;
                    q.push({x,y-1});
                }
                if(y+1 < m && grid[x][y+1] == 1) {
                    grid[x][y+1] = 2;
                    q.push({x,y+1});
                }
            }
        }
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) if(grid[i][j] == 1) return -1;
        }
        
        return time < 0 ? 0 : time;
    }
};
