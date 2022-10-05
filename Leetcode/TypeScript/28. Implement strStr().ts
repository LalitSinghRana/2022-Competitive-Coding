function strStr(haystack: string, needle: string): number {
    if(!needle) return 0;
    
    for(let i: number = 0; i<haystack.length; i++) {
        let str : string = haystack.substring(i, i+needle.length);
        if(str == needle) return i;
    }
    
    return -1;
};
