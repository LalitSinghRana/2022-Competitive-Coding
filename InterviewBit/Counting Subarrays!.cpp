int Solution::solve(vector<int> &A, int B) {
    int i=0, j=0, ans=0, sum=0;

    while(j<A.size()) {
        sum += A[j];
        while(sum >= B) {
            sum -= A[i];
            i++;
        }
        ans += (j-i+1);
        j++;
    }
    return ans;
}
