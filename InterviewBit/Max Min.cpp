int Solution::solve(vector<int> &A) {
    int n=A.size(), x=A[0], y=A[0];
    for(int i=1; i<n; i++) {
        x = max(A[i],x);
        y = min(A[i],y);
    }
    return x+y;
}
