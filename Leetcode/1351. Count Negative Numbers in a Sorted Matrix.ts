function countNegatives(grid: number[][]): number {
    let cnt: number = 0;
    for(let i=0; i<grid.length; i++) {
        for(let j=grid[i].length-1; j>=0; j--) if(grid[i][j] < 0) cnt++;
    }
    return cnt;
};
