string Solution::addBinary(string A, string B) {
    int n = A.size(), m = B.size(), c=0, i=0;

    reverse(A.begin(), A.end());
    reverse(B.begin(), B.end());

    string ans = "";

    for(i; i<min(n,m); i++) {
        int x = A[i]-'0', y = B[i]-'0';
        int r = (x+y+c)%2;
        c = (x+y+c)/2;
        ans += ('0' + r);
    }

    if (n > m) {
        for(i; i<n; i++) {
            int x = A[i]-'0';
            int r = (x+c)%2;
            c = (x+c)/2;
            ans += ('0' + r);
        }
    } else if (n < m) {
        for(i; i<m; i++) {
            int y = B[i]-'0';
            int r = (y+c)%2;
            c = (y+c)/2;
            ans += ('0' + r);
        }
    }

    if(c > 0) ans += ('0' + c);

    reverse(ans.begin(), ans.end());

    return ans;
}
