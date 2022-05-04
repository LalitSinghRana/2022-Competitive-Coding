int Solution::solve(string A) {
    int n = A.size();
    int c=0, v=0;

    for(int i=0; i<n; i++) {
        if(A[i]=='a'||A[i]=='e'||A[i]=='i'||A[i]=='o'||A[i]=='u') v++;
        else c++;
    }

    int cnt=0;
    for(int i=0; i<n; i++) {
        if(A[i]=='a'||A[i]=='e'||A[i]=='i'||A[i]=='o'||A[i]=='u') {
            cnt = (cnt + c)%1000000007;
            v--;
        } else {
            cnt = (cnt + v)%1000000007;
            c--;
        }
    }

    return cnt;
}
