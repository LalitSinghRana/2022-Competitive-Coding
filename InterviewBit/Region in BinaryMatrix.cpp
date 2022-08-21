int findlen(vector<vector<int> > &A, int i, int j) {
    queue<pair<int,int>> q;
    A[i][j] = 0;
    q.push({i,j});
    int cnt = 0;
    
    while(!q.empty()) {
        auto [x,y] = q.front();
        q.pop();
        cnt++;
        
        if(x-1 >= 0) {
            if(y-1 >= 0 && A[x-1][y-1]) {
                A[x-1][y-1] = 0;
                q.push({x-1,y-1});
            }
            if(A[x-1][y]) {
                A[x-1][y] = 0;
                q.push({x-1,y});
            }
            if(y+1 < A[x].size() && A[x-1][y+1]) {
                A[x-1][y+1] = 0;
                q.push({x-1,y+1});
            }
        }
        if(x+1 < A.size()) {
            if(y-1 >= 0 && A[x+1][y-1]) {
                A[x+1][y-1] = 0;
                q.push({x+1,y-1});
            }
            if(A[x+1][y]) {
                A[x+1][y] = 0;
                q.push({x+1,y});
            }
            if(y+1 < A[x].size() && A[x+1][y+1]) {
                A[x+1][y+1] = 0;
                q.push({x+1,y+1});
            }
        }
        if(y-1 >= 0 && A[x][y-1]) {
            A[x][y-1] = 0;
            q.push({x,y-1});
        }
        if(y+1 < A[x].size() && A[x][y+1]) {
            A[x][y+1] = 0;
            q.push({x,y+1});
        }
    }
    
    return cnt;
}

int Solution::solve(vector<vector<int> > &A) {
    int mx = 0;
    for(int i=0; i<A.size(); i++) {
        for(int j=0; j<A[i].size(); j++) {
            if(A[i][j]) mx = max(mx, findlen(A, i, j));
        }
    }
    
    return mx;
}
