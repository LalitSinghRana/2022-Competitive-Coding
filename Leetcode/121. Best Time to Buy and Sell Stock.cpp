class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mnPrice = INT_MAX, mxProfit = INT_MIN;
        
        for(int i=0; i<prices.size(); i++) {
            mnPrice = min(mnPrice, prices[i]);
            mxProfit = max(mxProfit, prices[i] - mnPrice);
        }
        
        return mxProfit;
    }
};
