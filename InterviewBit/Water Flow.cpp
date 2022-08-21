int Solution::solve(vector<vector<int> > &A) {
    int n = A.size(), m = A[0].size();
    vector<vector<bool> > b(n, vector<bool> (m,0)), r(n, vector<bool> (m,0));
    queue<pair<int,int>> bq, rq;
    
    for(int i=0; i<n;i++) {
        b[i][0] = 1;
        bq.push({i,0});
        r[i][m-1] = 1;
        rq.push({i,m-1});
    }
    
    for(int j=0; j<m;j++) {
        b[0][j] = 1;
        bq.push({0,j});
        r[n-1][j] = 1;
        rq.push({n-1,j});
    }
    
    while(!bq.empty()) {
        auto [x,y] = bq.front();
        bq.pop();
        
        if(x-1 >= 0 && !b[x-1][y] && A[x-1][y] >= A[x][y]) {
            b[x-1][y] = 1;
            bq.push({x-1,y});
        }
        if(x+1 < n && !b[x+1][y] && A[x+1][y] >= A[x][y]) {
            b[x+1][y] = 1;
            bq.push({x+1,y});
        }
        if(y-1 >= 0 && !b[x][y-1] && A[x][y-1] >= A[x][y]) {
            b[x][y-1] = 1;
            bq.push({x,y-1});
        }
        if(y+1 < m && !b[x][y+1] && A[x][y+1] >= A[x][y]) {
            b[x][y+1] = 1;
            bq.push({x,y+1});
        }
    }
    
    while(!rq.empty()) {
        auto [x,y] = rq.front();
        rq.pop();
        
        if(x-1 >= 0 && !r[x-1][y] && A[x-1][y] >= A[x][y]) {
            r[x-1][y] = 1;
            rq.push({x-1,y});
        }
        if(x+1 < n && !r[x+1][y] && A[x+1][y] >= A[x][y]) {
            r[x+1][y] = 1;
            rq.push({x+1,y});
        }
        if(y-1 >= 0 && !r[x][y-1] && A[x][y-1] >= A[x][y]) {
            r[x][y-1] = 1;
            rq.push({x,y-1});
        }
        if(y+1 < m && !r[x][y+1] && A[x][y+1] >= A[x][y]) {
            r[x][y+1] = 1;
            rq.push({x,y+1});
        }
    }
    
    int cnt = 0;
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) if(b[i][j] && r[i][j]) cnt++;
    }
    
    return cnt;
}
