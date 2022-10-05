let ans: number[][];
let cand: number[];
let t: number;
function combinationSum(candidates: number[], target: number): number[][] {
    ans = [];
    cand = candidates;
    cand.sort((a,b) => a-b);
    t = target;
    
    dfs([], 0, 0);
    return ans;
};

const dfs = (arr: number[], sum: number, i:number): void => {
    for(i; i<cand.length; i++) {
        if(sum + cand[i] === t) ans.push([...arr, cand[i]]);
        else if(sum + cand[i] > t) break;
        else dfs([...arr, cand[i]], sum + cand[i], i);
    }
    return;
}
