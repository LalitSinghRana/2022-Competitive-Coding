function longestCommonPrefix(strs: string[]): string {
    let ans: string = strs[0];
    
    for(let i=1; i<strs.length; i++) {
        let temp: string = '';
        
        for(let j=0; j<Math.min(ans.length, strs[i].length); j++) {
            if(ans[j] !== strs[i][j]) break;
            temp += ans[j];
        }
        
        ans = temp;
    }
    
    return ans;
};
