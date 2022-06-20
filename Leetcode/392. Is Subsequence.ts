function isSubsequence(s: string, t: string): boolean {
    let i: number = 0, ans: boolean = false;
    for(let j=0; j<t.length && i<s.length; j++) if(t[j] === s[i]) i++;
    if(i >= s.length) ans = true;
    return ans;
};
