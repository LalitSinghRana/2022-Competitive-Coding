class Solution {
public:
    int findMinFibonacciNumbers(int k) {
        vector<long long> f;
        f.push_back(1);
        f.push_back(1);
        
        while(f.back() < k) {
            int n = f.size();
            f.push_back(f[n-1] + f[n-2]);
        }
        
        int cnt = 0;
        for(int i = f.size()-1; i>=0 && k>0; i--) {
            if(f[i] <= k) {
                k -= f[i];
                cnt++;
            }
        }
        
        return cnt;
    }
};
