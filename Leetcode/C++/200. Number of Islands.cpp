class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int cnt = 0;
        for(int i=0; i<grid.size(); i++) {
            for(int j=0; j<grid[i].size(); j++) {
                if(grid[i][j] == '1') {
                    cnt++;
                    grid[i][j] = '0';
                    queue<pair<int,int>> q;
                    q.push({i,j});
                                        
                    while(!q.empty()) {
                        auto [x,y] = q.front();
                        q.pop();
                                                
                        if(x-1 >= 0 && grid[x-1][y] == '1') {
                            grid[x-1][y] = '0';
                            q.push({x-1,y});
                        }
                        if(x+1 < grid.size() && grid[x+1][y] == '1') {
                            grid[x+1][y] = '0';
                            q.push({x+1,y});
                        }
                        if(y-1 >= 0 && grid[x][y-1] == '1') {
                            grid[x][y-1] = '0';
                            q.push({x,y-1});
                        }
                        if(y+1 < grid[x].size() && grid[x][y+1] == '1') {
                            grid[x][y+1] = '0';
                            q.push({x,y+1});
                        }
                    }
                }
            }
        }
        
        return cnt;
    }
};
