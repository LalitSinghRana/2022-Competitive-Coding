class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        
        for(auto x : asteroids) {
            if(x < 0 && !st.empty() && st.top() > 0) {
                bool flag = 1;
                while(!st.empty() && st.top() > 0) {
                    if(abs(x) == st.top()) {
                        flag = 0;
                        st.pop();
                        break;
                    } else if(abs(x) < st.top()) {
                        flag = 0;
                        break;
                    } else {
                        st.pop();
                    }
                }
                
                if(flag) st.push(x);
            } else {
                st.push(x);
            }
        }
        
        vector<int> ans;
        while(!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};
