function permute(nums: number[]): number[][] {
    if(nums.length <= 1) return [nums];
    let ans:number[][] = [];
    
    for(let i=0; i<nums.length; i++) {
        let arr: number[] = [];
        for(let j=0; j<nums.length; j++) if(j!==i) arr.push(nums[j]);
        let res:number[][] = permute(arr);
        for(let j=0; j<res.length; j++) {
            res[j].push(nums[i]);
            ans.push(res[j]);
        }
    }
    
    return ans;
};
