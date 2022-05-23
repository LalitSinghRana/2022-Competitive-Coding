int Solution::solve(string A) {
    unordered_map<char,int> m;
    for(int i=0; i<A.size(); i++) m[A[i]]++;
    int odd=0;
    for(auto it : m) if(it.second % 2 == 1) odd++;

    return odd>1 ? 0 : 1;
}
