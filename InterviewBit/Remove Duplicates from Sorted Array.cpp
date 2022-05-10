int Solution::removeDuplicates(vector<int> &A) {
    int n=A.size(), i=0, j=1;
    if(!n) return 0;

    while(j<n) {
        if(A[i] == A[j]) j++;
        else {
            A[i+1] = A[j];
            i++; j++;
        }
    }

    return i+1;
}
