class Solution {
public:
    void rotate(vector<vector<int>>& A) {
        reverse(A.begin(), A.end());
        
        for(int i=0; i<A.size(); i++) {
            for(int j=0; j<i; j++) swap(A[i][j], A[j][i]);
        }
    }
};
