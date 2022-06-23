function heightChecker(heights: number[]): number {
    let expected: number[] = [...heights];
    expected.sort((a,b) => a-b);
    let cnt: number = 0;
    for(let i=0; i<expected.length; i++) if(expected[i] != heights[i]) cnt++;
    return cnt;
};
