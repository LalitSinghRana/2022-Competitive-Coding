class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size(), sum=0, idx=-1;
        vector<int> dif(n);
        
        for(int i=0; i<n; i++) {
            dif[i] = gas[i] - cost[i];
            sum += dif[i];
        }
        
        if(sum < 0) return -1;
        
        sum = 0;
        for(int i=0; i<n; i++) {
            sum += dif[i];
            if(sum < 0) {
                sum = 0;
                idx = -1;
            } else if(sum == dif[i]) idx = i;
        }
        
        return idx;
    }
};
