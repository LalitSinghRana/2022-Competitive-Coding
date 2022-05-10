// 2 pointer approach
int Solution::solve(vector<int> &A, int B) {
    sort(A.begin(), A.end());
    int i=0, j=1, n=A.size();

    while(i<n && j<n) {
        if(i!=j && A[j]-A[i] == B) return 1;
        else if(A[j]-A[i] < B) j++;
        else i++;
    }

    return 0;
}


// Hashing approach
int Solution::solve(vector<int> &A, int B) {
    unordered_set<int> s;

    for(int i=0; i<A.size(); i++) {
        int x = A[i]-B, y = B+A[i];
        if(s.find(x) != s.end() || s.find(y) != s.end()) return 1;
        s.insert(A[i]);
    }
    
    return 0;
}
