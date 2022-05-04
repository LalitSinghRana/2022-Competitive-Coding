int Solution::repeatedNumber(const vector<int> &A) {
    vector<int> arr(A.size(),0);
    for(int i=0; i<A.size(); i++) {
        if(arr[A[i] -1]) return A[i];
        else arr[A[i] -1] = 1;
    }
    return -1;
}
