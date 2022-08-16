function canPartition(nums: number[]): boolean {
    let sum: number = 0;
    for(let i=0; i<nums.length; i++) sum += nums[i];
    
    if(sum%2) return false;
    else return findSubSet(nums, sum/2);
};

const findSubSet = (nums: number[], t: number) => {
    let dp: boolean[][] = [];
    nums.sort((a,b) => a-b);
    
    for(let i=0; i<=nums.length; i++) {
        dp.push([]);
        for(let j=0; j<=t; j++) dp[i].push(false);
    }
    
    for(let i=0; i<dp.length; i++) dp[i][0] = true;
        
    for(let i=1; i<dp.length; i++) {
        for(let j=1; j<=t; j++) dp[i][j] = dp[i-1][j] || (j-nums[i-1] >=0 && dp[i-1][j-nums[i-1]]);
    }
        
    return dp[dp.length-1][dp[0].length-1];
}
