class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size(), m = matrix[0].size(), ans = 0;
        vector<vector<int>> A(n, vector<int>(m,0));
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                A[i][j] = matrix[i][j] - '0';
                ans = max(ans, A[i][j]);
            }
        }
        
        for(int i=1; i<n; i++) {
            for(int j=1; j<m; j++) {
                if(A[i][j]) {
                    A[i][j] = 1 + min(A[i-1][j-1], min(A[i-1][j], A[i][j-1]));
                }
                
                ans = max(ans, A[i][j]);
            }
        }
        
        return ans*ans;
    }
};
