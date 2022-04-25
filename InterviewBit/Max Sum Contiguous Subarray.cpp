int Solution::maxSubArray(const vector<int> &A) {
    int msf=INT_MIN, meh=0, n=A.size();
    for(int i=0; i<n; i++) {
        meh += A[i];
        if(meh<A[i]) meh = A[i];
        if(msf<meh) msf = meh;
    }
    return msf;
}
