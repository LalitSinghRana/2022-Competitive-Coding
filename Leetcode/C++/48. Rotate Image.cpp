class Solution {
public:
    void rotate(vector<vector<int>>& A) {
        int n = A.size();
        
        for(int i=0; i<n; i++) {
            auto l = 0, r = i;
            while(l < r) {
                swap(A[r][l], A[l][r]);
                l++; r--;
            }
            
            l = i;
            r = n-1;
            while(i && l<r) {
                swap(A[r][l], A[l][r]);
                l++; r--;
            }
        }
        
        for(auto &v : A) reverse(v.begin(), v.end());
    }
};
