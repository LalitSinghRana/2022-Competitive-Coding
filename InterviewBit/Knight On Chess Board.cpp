int Solution::knight(int A, int B, int C, int D, int E, int F) {
    queue<pair<int,int>> q;
    vector<vector<bool>> v(A+1, vector<bool>(B+1));
    
    v[C][D] = 1;
    q.push({C,D});
    
    int mn = 0;
    
    while(!q.empty()) {
        int s = q.size();
        
        while(s--) {
            auto [x,y] = q.front();
            q.pop();
            
            if(x == E && y == F) return mn;
            
            if(x-2 > 0) {
                if(y-1 > 0 && !v[x-2][y-1]) {
                    v[x-2][y-1] = 1;
                    q.push({x-2,y-1});
                }
                if(y+1 <= B && !v[x-2][y+1]) {
                    v[x-2][y+1] = 1;
                    q.push({x-2,y+1});
                }
            }
            if(x+2 <= A) {
                if(y-1 > 0 && !v[x+2][y-1]) {
                    v[x+2][y-1] = 1;
                    q.push({x+2,y-1});
                }
                if(y+1 <= B && !v[x+2][y+1]) {
                    v[x+2][y+1] = 1;
                    q.push({x+2,y+1});
                }
            }
            if(y-2 > 0) {
                if(x-1 > 0 && !v[x-1][y-2]) {
                    v[x-1][y-2] = 1;
                    q.push({x-1,y-2});
                }
                if(x+1 <= A && !v[x+1][y-2]) {
                    v[x+1][y-2] = 1;
                    q.push({x+1,y-2});
                }
            }
            if(y+2 <= B) {
                if(x-1 > 0 && !v[x-1][y+2]) {
                    v[x-1][y+2] = 1;
                    q.push({x-1,y+2});
                }
                if(x+1 <= A && !v[x+1][y+2]) {
                    v[x+1][y+2] = 1;
                    q.push({x+1,y+2});
                }
            }
        }
        mn++;
    }
    
    return -1;
}
