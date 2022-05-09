int Solution::sqrt(int A) {
    if(A == 0) return 0;

    long long int l=1, r=A, mid, ans=0;

    while(l<=r) {
        mid = r - (r-l)/2;
        if(mid <= A/mid) {
            ans = mid;
            l = mid+1;
        }else r = mid - 1;
    }

    return ans;
}
