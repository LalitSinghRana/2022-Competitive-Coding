int Solution::solve(string a) {
    int count=0;
    int ans=0;

    for(int i=0;i<a.length();i++) {
        if(a[i]=='(') count++;
        else {
            count--;
            if(count<0) {
                ans++;
                count=0;
            }
        }
    }
    ans+=count;
    return ans;
}
