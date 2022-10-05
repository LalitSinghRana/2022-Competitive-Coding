function maxDepth(s: string): number {
    let arr: string[] = [];
    let ans: number = 0;
    s.split('').forEach(x => {
        if(x === '(') {
            arr.push(x);
            ans = Math.max(ans, arr.length);
        } else if(x === ')') arr.pop();
    });
    return ans;
};
