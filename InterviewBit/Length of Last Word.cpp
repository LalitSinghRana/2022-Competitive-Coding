int Solution::lengthOfLastWord(const string A) {
    int ans=0, i=A.length()-1;
    
    for(i; i>=0; i--) {
        if(A[i] != ' ') break;
    }

    for(i; i>=0; i--) {
        if(A[i] != ' ') ans++;
        else break;
    }

    return ans;
}
