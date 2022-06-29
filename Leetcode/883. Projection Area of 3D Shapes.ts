function projectionArea(grid: number[][]): number {
    let ans: number = 0;
    for(let i=0; i<grid.length; i++) {
        let a: number = Number.MIN_SAFE_INTEGER;
        for(let j=0; j<grid[i].length; j++) a = Math.max(grid[i][j],a);
        ans += a;
    }
    
    for(let i=0; i<grid[0].length; i++) {
        let a: number = Number.MIN_SAFE_INTEGER;
        for(let j=0; j<grid.length; j++) a = Math.max(grid[j][i],a);
        ans += a;
    }
    
    for(let i=0; i<grid.length; i++) {
        for(let j=0; j<grid[i].length; j++) if(grid[i][j]) ans++;
    }
    
    return ans;
};
