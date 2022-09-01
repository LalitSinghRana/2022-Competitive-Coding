class Solution {
public:
    int maxArea(vector<int>& H) {
        int mx = 0, l = 0, r = H.size()-1;
        while(l<r) {
            int ar = min(H[l],H[r]) * (r-l);
            mx = max(mx, ar);
            H[l] <= H[r] ? l++ : r--;
        }
        return mx;
    }
};
