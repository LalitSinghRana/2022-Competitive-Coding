int Solution::solve(vector<int> &A, int B) {
    unordered_set<int> s;
    int ans=0;

    for(int i=0; i<A.size(); i++) {
        int x = A[i] ^ B;
        if(s.find(x) != s.end()) ans++;
        s.insert(A[i]);
    }

    return ans;
}
