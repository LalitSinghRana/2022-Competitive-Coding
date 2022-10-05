function merge(intervals: number[][]): number[][] {
    intervals.sort((a,b) => {
        return a[0] !== b[0] ? a[0] - b[0] : a[1] - b[1];
    });
    let ans: number[][] = [];
    ans.push(intervals[0]);
    
    for(let i=1; i<intervals.length; i++) {
        if(ans[ans.length-1][1] < intervals[i][0]) ans.push(intervals[i]);
        else if (ans[ans.length-1][1] < intervals[i][1]) ans[ans.length-1][1] = intervals[i][1];
    }
    
    return ans;
};
