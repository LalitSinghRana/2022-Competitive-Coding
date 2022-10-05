function runningSum(nums: number[]): number[] {
    let ans: number[] = [];
    ans.push(nums[0])
    for(let i=1; i<nums.length; i++) {
        ans.push(nums[i] + ans[i-1]);
    }
    return ans;
};
