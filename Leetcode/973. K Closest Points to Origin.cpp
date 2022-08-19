class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        map<int,vector<vector<int>>> m;
        
        for(int i=0; i<points.size(); i++) {
            int key = pow(points[i][0],2) + pow(points[i][1],2);
            m[key].push_back(points[i]);
        }
        
        vector<vector<int>> ans;
        
        for(auto& [key,value] : m) {
            for(auto &arr : value) ans.push_back(arr);
            if(ans.size() >= k) break;
        }
        
        return ans;
    }
};
