function maxProfit(prices: number[]): number {
    let arr: number[] = [];
    let n: number = prices.length;
    arr[n-1] = prices[n-1];
    for(let i=n-2; i>=0; i--) {
        arr[i] = Math.max(prices[i],arr[i+1]);
    }
    
    let ans=0;
    for(let i=0; i<n; i++) ans = Math.max(ans, arr[i]-prices[i]);
    
    return ans;
};
