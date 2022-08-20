unordered_map<int,unordered_set<int>> g;
unordered_set<int> v;
bool flag;
int n;

void dfs(int a) {
    if(g[a].find(n) != g[a].end()) {
        flag = true;
        return;
    }
    v.insert(a);
    
    for(auto x : g[a]) {
        if(v.find(x) == v.end()) dfs(x);
        if(flag) return;
    }
}

int Solution::solve(int A, vector<vector<int> > &B) {
    flag = false;
    n = A;
    
    for(int i=0; i<B.size(); i++) {
        g[B[i][0]].insert(B[i][1]);
    }
    
    dfs(1);
    
    g.clear();
    v.clear();
    
    return flag;
}
