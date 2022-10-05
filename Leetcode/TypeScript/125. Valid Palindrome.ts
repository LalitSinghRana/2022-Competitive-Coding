function isPalindrome(s: string): boolean {
    s = s.toLowerCase();
    s = s.replace(/[^0-9a-z]+/g,'');
    
    let i: number = 0, j: number = s.length - 1;
    
    while(i<j) {
        if(s[i] !== s[j]) return false;
        i++; j--;
    }
    
    return true;
};
