class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> par(n+1), rank(n+1,1);
        for(int i=1; i<=n; i++) par[i] = i;
        
        for(auto& arr : edges) {
            int p1 = findPar(arr[0], par);
            int p2 = findPar(arr[1], par);
            
            if(p1 == p2) return arr;
            
            if(rank[p1] >= rank[p2]) {
                par[p2] = p1;
                rank[p1]++;
            } else {
                par[p1] = p2;
                rank[p2]++;
            }
        }
        return {};
    }
    
    int findPar(int x, vector<int> &par) {
        while(par[x] != x) x = par[x];
        return x;
    }
};
