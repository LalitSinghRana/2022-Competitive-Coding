vector<int> Solution::intersect(const vector<int> &A, const vector<int> &B) {
    int n = A.size(), m = B.size(), i=0, j=0;
    vector<int> ans;

    while(i<n && j<m) {
        if(A[i] == B[j]) {
            ans.push_back(A[i]);
            i++; j++;
        } else if(A[i] < B[j]) i++;
        else j++;
    }

    return ans;
}
