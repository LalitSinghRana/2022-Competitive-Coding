int Solution::solve(vector<int> &A, int B) {
    priority_queue<int> pq;
    for(int a : A) pq.push(a);

    int ans=0;
    while(B--) {
        int x = pq.top();
        ans += x;
        pq.pop();
        pq.push(x-1);
    }

    return ans;
}
