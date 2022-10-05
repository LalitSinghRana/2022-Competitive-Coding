function insert(intervals: number[][], newInterval: number[]): number[][] {
    let ans: number[][] = [];
    intervals.push(newInterval);
    intervals.sort((a,b) => a[0]-b[0]);
    ans.push(intervals[0]);
    
    for(let i=1; i<intervals.length; i++) {
        if(intervals[i][0] <= ans[ans.length-1][1]) {
            ans[ans.length-1][1] = Math.max(ans[ans.length-1][1], intervals[i][1]);
        } else ans.push(intervals[i]);
    }
    
    return ans;
};
