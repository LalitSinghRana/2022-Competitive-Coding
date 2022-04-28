int Solution::solve(vector<int> &A) {
    int n=A.size();
    sort(A.begin(),A.end());
    vector<int> temp;

    for(int i=0; i<n-1; i++) {
        if(A[i] == (n-1-i) && A[i] != A[i+1]) return 1;
    }

    if(A[n-1]==0) return 1;

    return -1;
}
