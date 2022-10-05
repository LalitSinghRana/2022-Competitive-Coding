// Sol - 1
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int,int>> pq;
        for(auto y : arr) pq.push({-abs(x-y), -y});
        
        vector<int> ans;
        while(k--) {
            ans.push_back(-pq.top().second);
            pq.pop();
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};


// Sol - 2
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        int r = upper_bound(arr.begin(), arr.end(),x) - arr.begin();
        int l = r-1;
        
        while(k--) {
            if(r>=n || (l>=0 && (x-arr[l] <= arr[r]-x))) l--;
            else r++;
        }
                
        return vector<int>(begin(arr)+l+1, begin(arr)+r);
    }
};





