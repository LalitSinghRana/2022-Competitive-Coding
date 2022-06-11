function isPalindrome(x: number): boolean {
    if(x<0) return false;
    let str:string = x.toString();
    let i:number=0, j:number=str.length-1;
    while(i<j) {
        if(str[i] !== str[j]) return false;
        i++; j--;
    }
    return true;
};
