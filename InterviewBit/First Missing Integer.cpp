int Solution::firstMissingPositive(vector<int> &A) {
    bool contains_one = false;
        for(int x: A){
            if(x == 1){
                contains_one = true;
                break;
            }
        }
        if(!contains_one) return 1;
        
        int n = A.size();
        if(n == 1) return 2;
        
        for(int i = 0; i < n; ++i)
            if(A[i] <= 0 || A[i] > n) A[i] = 1;
        
        for(int i = 0; i < n; ++i){
            int x = abs(A[i]);
            if(A[x-1] > 0) A[x-1] *= -1;
        }
        
        for(int i = 0; i < n; ++i)
            if(A[i] > 0) return i+1;
        
        return n+1;
}
