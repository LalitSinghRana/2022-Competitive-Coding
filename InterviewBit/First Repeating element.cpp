int Solution::solve(vector<int> &A) {
    unordered_map<int,int> um;
    for(int i=0; i<A.size(); i++) {
        if(um.find(A[i]) != um.end()) um[A[i]]++;
        else um[A[i]] = 1;
    }

    for(int i=0; i<A.size(); i++) if(um[A[i]] > 1) return A[i];

    return -1;
}
