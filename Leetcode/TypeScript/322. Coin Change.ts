function coinChange(coins: number[], amt: number): number {
    let dp: number[] = [];
    for(let i=0; i<=amt; i++) dp.push(amt+1);
    dp[0] = 0;
    
    for(let i=1; i<=amt; i++) {
        for(let j=0; j<coins.length; j++) {
            if(i-coins[j] >= 0) dp[i] = Math.min(dp[i], 1+dp[i-coins[j]]);
        }
    }
    
    return dp[amt] === amt+1 ? -1 : dp[amt];
};
