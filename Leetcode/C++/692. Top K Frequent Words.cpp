class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> m;
        auto cmpr = [](auto& a, auto& b) {
            if(a.first == b.first) return !lexicographical_compare(a.second.begin(), a.second.end(), b.second.begin(), b.second.end());
            else return a.first < b.first;
        };
        priority_queue<pair<int,string>, vector<pair<int,string>>, decltype(cmpr)> pq(cmpr);
        
        for(auto s : words) m[s]++;
        for(auto [key, val] : m) pq.push({val,key});
        
        vector<string> ans;
        while(k--) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        
        return ans;
    }
};
