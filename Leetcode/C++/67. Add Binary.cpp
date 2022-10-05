class Solution {
public:
    string addBinary(string a, string b) {
        int c = 0, i=0, j=0;
        string ans = "";
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        
        while(i < a.size() || j < b.size()) {
            if(i >= a.size()) {
                int x = (b[j++] - '0') + c;
                ans += (x%2 + '0');
                c = x/2;
            } else if(j >= b.size()) {
                int x = (a[i++] - '0') + c;
                ans += (x%2 + '0');
                c = x/2;
            } else {
                int x = (a[i++] - '0') + (b[j++] - '0') + c;
                ans += (x%2 + '0');
                c = x/2;
            }
        }
        
        if(c) ans += (c + '0');
        
        reverse(ans.begin(),ans.end());
        
        return ans;
    }
};
