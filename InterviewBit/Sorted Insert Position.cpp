int Solution::searchInsert(vector<int> &A, int B) {
    if(B < A[0]) return 0;
    if(B > A.back()) return A.size();

    int l=0, r=A.size()-1, m;

    while(l<=r) {
        m = r - (r-l)/2;
        if(A[m] == B) return m;
        else if(A[m] < B) l = m+1;
        else  r = m-1;
    }

    return r+1;
}
