function lengthOfLongestSubstring(s: string): number {
    let i:number = 0, j:number = 0, ans:number = 0;
    let mySet = new Set<string>();
    
    for(j; j<s.length; j++) {
        while(mySet.has(s[j])) mySet.delete(s[i++]);
        mySet.add(s[j]);
        if(mySet.size > ans) ans = mySet.size;
    }
    
    return ans;
};
