function climbStairs(n: number): number {
    let arr: number[] = [];
    arr.push(0);
    arr.push(1);
    arr.push(2);
    for(let i=3; i<=n; i++) arr.push(arr[i-1] + arr[i-2]);
    
    return arr[n];
};
