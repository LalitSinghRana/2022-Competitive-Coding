class Solution {
public:
    int myAtoi(string s) {
        const int INTMIN = pow(-2, 31);
        const int INTMAX = pow(2, 31) - 1;
        
        bool isNeg = false;
        int i = 0;
        for(i=0; i<s.size(); i++) {
            if(s[i] != ' ') break;
        }

        if(s[i] == '-') {
            isNeg = true;
            i++;
        } else if(s[i] == '+') i++;

        string s1 = s.substr(i);
        long long int num = 0;

        for(int i = 0; i<s1.size(); i++) {
            if(s1[i] >= '0' && s1[i] <= '9') {
                num = num*10 + (s1[i] - '0');
                if(num > INTMAX) break;
            }
            else break;
        }
        
        if(isNeg) num = -num;

        if(num > INTMAX) return INTMAX;
        else if(num < INTMIN) return INTMIN;
        return num;
    }
};
