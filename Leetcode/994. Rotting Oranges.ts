function orangesRotting(grid: number[][]): number {
    let q: number[][] = [];
    let cnt: number = 0;
    
    for(let i=0; i<grid.length; i++) {
        for(let j=0; j<grid[i].length; j++) {
            if(grid[i][j] === 2) {
                grid[i][j] = 0;
                addToQ(i,j,q,grid);
            }
        }
    }
    
    while(q.length) {
        let n: number = q.length;
        cnt++;
        while(n--) {
            let [i,j] = q.shift();
            addToQ(i,j,q,grid);
        }
    }
    
    for(let i=0; i<grid.length; i++) {
        for(let j=0; j<grid[i].length; j++) {
            if(grid[i][j] === 1) return -1;
        }
    }
    
    return cnt;
};


let addToQ = (x: number, y: number, q: number[][], grid: number[][]): void => {
    if(x-1>=0 && grid[x-1][y] === 1) {
        q.push([x-1,y]);
        grid[x-1][y] = 0;
    }
    if(y-1>=0 && grid[x][y-1] === 1) {
        q.push([x,y-1]);
        grid[x][y-1] = 0;
    }
    if(x+1<grid.length && grid[x+1][y] === 1) {
        q.push([x+1,y]);
        grid[x+1][y] = 0;
    }
    if(y+1<grid[x].length && grid[x][y+1] === 1) {
        q.push([x,y+1]);
        grid[x][y+1] = 0;
    }
}
