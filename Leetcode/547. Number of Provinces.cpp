class Solution {
public:
    int findCircleNum(vector<vector<int>>& g) {
        int n = g.size(), cnt = 0;
        vector<int> vis(n);
        
        for(int i=0; i<n; i++) {
            if(!vis[i]) {
                cnt++;
                queue<int> q;
                q.push(i);
                vis[i] = 1;
                
                while(!q.empty()) {
                    int k = q.front();
                    q.pop();
                    for(int j=0; j<n; j++) {
                        if(j!=k && g[k][j] && !vis[j]) {
                            vis[j] = 1;
                            q.push(j);
                        }
                    }
                }
            }
        }
        
        return cnt;
    }
};
/*
1,1,0
1,1,0
0,0,1
*/
