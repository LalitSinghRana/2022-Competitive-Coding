vector<int> Solution::getRow(int A) {
    vector<int> ans(A+1);
    ans[0] = 1;
    for(int i=1; i<=A; i++) {
        ans[i] = (ans[i-1]*(A+1-i))/i;
    }
    return ans;
}
