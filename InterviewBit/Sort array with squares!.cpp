vector<int> Solution::solve(vector<int> &A) {
    int n=A.size(), i=0, j=0;

    for(i; i<n; i++) if(A[i]>=0) break;

    j = i-1;

    vector<int> ans;

    while(i<n || j>=0) {
        if(i>=n) {
            ans.push_back(A[j]*A[j]);
            j--;
        } else if(j<0) {
            ans.push_back(A[i]*A[i]);
            i++;
        } else {
            if(A[i]*A[i] <= A[j]*A[j]) {
                ans.push_back(A[i]*A[i]);
                i++;
            } else {
                ans.push_back(A[j]*A[j]);
                j--;
            }
        }
    }

    return ans;
}
