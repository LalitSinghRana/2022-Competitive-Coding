class Solution {
public:
    bool isPalindrome(string s) {
        string str;
        for(auto c : s) {
            if((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z')) str += c;
            else if(c >= 'A' && c<= 'Z') str += (c + ('a' - 'A'));
        }
        
        int n = str.size();
        for(int i=0; i<n/2; i++) if(str[i] != str[n-1-i]) return false;
        
        return true;
    }
};
