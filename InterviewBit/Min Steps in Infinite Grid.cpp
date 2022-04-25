int Solution::coverPoints(vector<int> &A, vector<int> &B) {
    int ans=0, n=A.size();
    for(int i=1; i<n; i++) {
        int x, y, d;

        (A[i]>=A[i-1]) ? x = A[i]-A[i-1] : x = A[i-1]-A[i];
        (B[i]>=B[i-1]) ? y = B[i]-B[i-1] : y = B[i-1]-B[i];

        if(x <= y) {
            d = x;
            x -= d;
            y -= d;
        } else {
            d = y;
            x -= d;
            y -= d;
        }

        ans = ans + x+y+d;
    }

    return ans;
}
