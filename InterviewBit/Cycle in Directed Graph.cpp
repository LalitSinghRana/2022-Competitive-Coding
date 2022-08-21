unordered_set<int> v, p;
unordered_map<int, vector<int>> g;
bool flag;

void findLoop(int a) {
    if(p.find(a) != p.end()) {
        flag = true;
        v.insert(a);
        return;
    }
    
    p.insert(a);
    
    for(auto x : g[a]) {
        if(v.find(x) == v.end()) findLoop(x);
        if(flag) return;
    }
    
    p.erase(a);
    v.insert(a);
}

int Solution::solve(int A, vector<vector<int> > &B) {
    flag = false;
    
    for(int i=0; i<B.size(); i++) g[B[i][0]].push_back(B[i][1]);
    
    for(auto [k,v1] : g) if(v.find(k) == v.end()) findLoop(k);
    
    v.clear();
    p.clear();
    g.clear();
    
    return flag;
}
