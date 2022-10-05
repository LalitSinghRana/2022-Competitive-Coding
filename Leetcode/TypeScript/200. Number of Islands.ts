function numIslands(grid: string[][]): number {
    let cnt: number = 0;
    
    for(let i=0; i<grid.length; i++) {
        for(let j=0; j<grid[i].length; j++) {
            if(grid[i][j] === '1') {
                cnt++;
                grid[i][j] = '2';
                
                let q: number[][] = [];
                q.push([i,j]);
                while(q.length) {
                    let [x,y] = q.shift();
                    if(x-1>=0 && grid[x-1][y] === '1') {
                        grid[x-1][y] = '2';
                        q.push([x-1,y]);
                    }
                    if(y-1>=0 && grid[x][y-1] === '1') {
                        grid[x][y-1] = '2';
                        q.push([x,y-1]);
                    }
                    if(x+1<grid.length && grid[x+1][y] === '1') {
                        grid[x+1][y] = '2';
                        q.push([x+1,y]);
                    }
                    if(y+1<grid[x].length && grid[x][y+1] === '1') {
                        grid[x][y+1] = '2';
                        q.push([x,y+1]);
                    }
                }
            }
        }
    }
    
    return cnt;
};
