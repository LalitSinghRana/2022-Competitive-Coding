vector<int> Solution::dNums(vector<int> &A, int B) {
    unordered_map<int,int> m;
    for(int i=0; i<B; i++) m[A[i]]++;
    
    vector<int> ans;
    ans.push_back(m.size());
    for(int i=B; i<A.size(); i++) {
        m[A[i]]++;
        m[A[i-B]]--;
        if(!m[A[i-B]]) m.erase(A[i-B]);
        ans.push_back(m.size());
    }

    return ans;
}
