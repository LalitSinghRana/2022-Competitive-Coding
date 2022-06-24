function maximumWealth(A: number[][]): number {
    let maxSum: number = Number.MIN_SAFE_INTEGER;
    for(let i=0; i<A.length; i++) {
        let curSum: number = 0;
        for(let j=0; j<A[i].length; j++) curSum += A[i][j];
        maxSum = Math.max(maxSum, curSum);
    }
    return maxSum;
};
