function removePalindromeSub(s: string): number {
    let i=0, j=s.length - 1;
    
    while(i<j) {
        if(s[i] !== s[j]) return 2;
        i++; j--;
    }
    
    return 1;
};
