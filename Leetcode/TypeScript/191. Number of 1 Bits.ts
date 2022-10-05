function hammingWeight(n: number): number {
    let cnt: number = 0
    while(n !== 0) {
        n = n&(n-1);
        cnt++;
    }
    return cnt;
};
