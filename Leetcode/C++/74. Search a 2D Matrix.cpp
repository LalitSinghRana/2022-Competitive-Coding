class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int t = 0, b = matrix.size()-1;
        while(t<=b) {
            int m = (t+b)/2;
            if(matrix[m][0] <= target && target <= matrix[m][matrix[m].size()-1]) {
                int l=0, r=matrix[m].size()-1;
                
                while(l<=r) {
                    int mid = (l+r)/2;
                    if(matrix[m][mid] == target) return true;
                    else if(matrix[m][mid] > target) r = mid-1;
                    else l = mid+1;
                }
                
                return false;
            } else if(matrix[m][0] > target) b = m-1;
            else t = m+1;
        }
        
        return false;
    }
};
