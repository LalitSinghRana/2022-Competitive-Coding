class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        
        long div = 1;
        while(x >= 10*div) div *= 10;
        
        while(div >= 10) {
            int l = x%10, r = x/div;
            if(l != r) return 0;
            
            x %= div;
            x /= 10;
            
            div /= 100;
        }
        
        return 1;
    }
};
