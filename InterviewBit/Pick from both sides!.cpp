int Solution::solve(vector<int> &A, int B) {
    int i=0, j=A.size()-1, ans=0, sum=0;

    for(i; i<B; i++) sum += A[i];
    i--;
    ans = sum;
    
    while(i>=0) {
        sum = sum -A[i] + A[j];
        if(sum > ans) ans = sum;
        i--; j--;
    }

    return ans;
}
