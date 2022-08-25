class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> v(26);
        priority_queue<int> pq;
        queue<pair<int,int>> q;
        for(auto x : tasks) v[x - 'A']++;
        for(auto y : v) if(y) pq.push(y);
        
        int cnt = 0;
        while(!pq.empty() || !q.empty()) {
            cnt++;
            if(!pq.empty()) {
                int x = pq.top();
                pq.pop();

                x--;
                if(x) q.push({cnt+n,x});
            }
            
            if(!q.empty()) {
               auto [t,y] = q.front();
                if(t == cnt) {
                    q.pop();
                    pq.push(y);
                } 
            }
        }
        
        return cnt;
    }
};
