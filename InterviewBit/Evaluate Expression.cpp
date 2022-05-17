int Solution::evalRPN(vector<string> &A) {
    stack<string> s;
    for(int i=0; i<A.size(); i++) {
        if(A[i]=="+") {
            int y = stoi(s.top());
            s.pop();
            int x = stoi(s.top());
            s.pop();
            s.push(to_string(x+y));
        } else if(A[i]=="-") {
            int y = stoi(s.top());
            s.pop();
            int x = stoi(s.top());
            s.pop();
            s.push(to_string(x-y));
        } else if(A[i]=="*") {
            int y = stoi(s.top());
            s.pop();
            int x = stoi(s.top());
            s.pop();
            s.push(to_string(x*y));
        } else if(A[i]=="/") {
            int y = stoi(s.top());
            s.pop();
            int x = stoi(s.top());
            s.pop();
            s.push(to_string(x/y));
        } else s.push(A[i]);
    }

    return stoi(s.top());
}
