class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& A) {
        int t=0, b=A.size()-1, l=0, r=A[0].size()-1, dir=0;
        vector<int> ans;
        while(ans.size() <  A.size() * A[0].size()) {
            if(dir == 0) {
                int j = l;
                while(j <= r) ans.push_back(A[t][j++]);
                t++;
                dir = 1;
            } else if(dir == 1) {
                int i = t;
                while(i <= b) ans.push_back(A[i++][r]);
                r--;
                dir = 2;
            } else if(dir == 2) {
                int j = r;
                while(j >= l) ans.push_back(A[b][j--]);
                b--;
                dir = 3;
            } else if(dir == 3) {
                int i = b;
                while(i >= t) ans.push_back(A[i--][l]);
                l++;
                dir = 0;
            }
        }
        
        return ans;
    }
};
