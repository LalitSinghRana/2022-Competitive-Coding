function longestPalindrome(s: string): number {
    let m = new Map<string,number>();
    let arr = s.split
    
    for(let i=0; i<s.length; i++) m.set(s[i], (m.get(s[i]) ?? 0) +1);
    
    let flag: boolean = false;
    let ans:number = 0;
    for(const [key, value] of m.entries()) {
        if(value%2) flag = true;
        ans += (value - value%2)
    }
    
    return flag ? ans+1 : ans;
};
