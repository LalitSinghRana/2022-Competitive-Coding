class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> vis(n);
        queue<int> q;
        q.push(0);
        vis[0] = 1;
        
        while(!q.empty()) {
            int a = q.front();
            q.pop();
            for(auto x : rooms[a]) {
                if(!vis[x]) {
                    vis[x] = 1;
                    q.push(x);
                }
            }
        }
        
        for(auto f : vis) if(!f) return f;
        return true;
    }
};
