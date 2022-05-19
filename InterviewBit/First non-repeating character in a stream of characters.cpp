string Solution::solve(string A) {
    queue<char> q;
    vector<int> v(26, 0);
    string ans;

    for(int i=0; i<A.size(); i++) {
        q.push(A[i]);
        v[A[i]-'a']++;

        while(!q.empty() && v[q.front()-'a'] != 1) q.pop();
        if(q.empty()) ans += '#';
        else ans += q.front();
    }

    return ans;
}
