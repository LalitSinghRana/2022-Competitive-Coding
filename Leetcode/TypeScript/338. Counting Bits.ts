function countBits(n: number): number[] {
    let arr: number[] = [];
    arr.push(0);
    for(let i=1; i<=n; i++) {
        let t: number = arr[Math.floor(i/2)] + i%2;
        arr.push(t);
    }
    return arr;
};
