class Solution {
public:
    
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {        
        if(n == 1) return {0};
        vector<vector<int>> g(n);        
        vector<int> degree(n, 0);
        
        for(auto arr : edges) {
            g[arr[0]].push_back(arr[1]);
            g[arr[1]].push_back(arr[0]);
            degree[arr[0]]++;
            degree[arr[1]]++;
        }
        
        queue<int> q;
        
        for(int i=0; i<n; i++) if(degree[i] == 1) q.push(i);
        
        while(n > 2) {
            int size = q.size();
            n -= size;
            
            while(size--) {
                int x = q.front();
                q.pop();
                
                for(auto a : g[x]) {
                    degree[a]--;
                    if(degree[a] == 1) q.push(a);
                }
            }
        }
        
        vector<int> ans;
        
        while(!q.empty()) {
            ans.push_back(q.front());
            q.pop();
        }
        
        return ans;
    }
};
