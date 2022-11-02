class Solution {
public:
    vector<int> c_sum;
    Solution(vector<int>& w) {
        c_sum.push_back(w[0]);
        for(int i=1; i<w.size(); i++) c_sum.push_back(c_sum[i-1] + w[i]);
    }
    
    int pickIndex() {
        auto rand_wt = rand() % c_sum.back();
        return upper_bound(c_sum.begin(), c_sum.end(), rand_wt) - c_sum.begin();
    }
};
