class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {      
        int a=-1, b=-1, n = nums.size();
        vector<int> ans;
        
        for(int i=0; i<n; i++) {
            if(nums[i] >= 0) {
                b = i;
                a = i-1;
                break;
            }
        }
        
        if(b == -1) {
            b = n;
            a = n-1;
        }
        
        while(a >=0 || b < n) {
            if(a < 0) ans.push_back(pow(nums[b++],2));
            else if(b >= n) ans.push_back(pow(nums[a--],2));
            else if(abs(nums[a]) < nums[b]) ans.push_back(pow(nums[a--],2));
            else ans.push_back(pow(nums[b++],2));
        }
        
        return ans;
    }
};
