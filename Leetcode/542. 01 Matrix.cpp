class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> ans(n, vector<int> (m,-1));
        queue<pair<int,int>> q;
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(mat[i][j] == 0) {
                    q.push({i,j});
                    ans[i][j] = 0;
                }
            }
        }
        
        while(!q.empty()) {
            pair<int,int> p = q.front();
            q.pop();
            int x = p.first, y = p.second;
            
            if(x-1 >= 0 && ans[x-1][y] == -1) {
                ans[x-1][y] = ans[x][y] + 1;
                q.push({x-1,y});
            }
            if(x+1 < n && ans[x+1][y] == -1) {
                ans[x+1][y] = ans[x][y] + 1;
                q.push({x+1,y});
            }
            if(y-1 >= 0 && ans[x][y-1] == -1) {
                ans[x][y-1] = ans[x][y] + 1;
                q.push({x,y-1});
            }
            if(y+1 < m && ans[x][y+1] == -1) {
                ans[x][y+1] = ans[x][y] + 1;
                q.push({x,y+1});
            }
        }
        
        return ans;
    }
};
