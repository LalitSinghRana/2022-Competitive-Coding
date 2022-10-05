function updateMatrix(mat: number[][]): number[][] {
    let f: boolean[][] = [];
    let ans: number[][] = [];
    let q: number[][] = [];
    
    for(let i=0; i<mat.length; i++) {
        f.push([]);
        ans.push([])
        for(let j=0; j<mat[i].length; j++) {
            f[i].push(false);
            ans[i].push(0);
            if(mat[i][j] === 0) {
                q.push([i,j]);
                f[i][j] = true;
            }
        }
    }
    
    while(q.length) {
        let [x,y] = q.shift();
        if(x-1>=0 && !f[x-1][y]) {
            ans[x-1][y] = mat[x-1][y]===0 ? 0 : ans[x][y] + 1;
            q.push([x-1,y]);
            f[x-1][y] = true;
        }
        if(y+1<mat[x].length && !f[x][y+1]) {
            ans[x][y+1] = mat[x][y+1]===0 ? 0 : ans[x][y] + 1;
            q.push([x,y+1]);
            f[x][y+1] = true;
        }
        if(x+1<mat.length && !f[x+1][y]) {
            ans[x+1][y] = mat[x+1][y]===0 ? 0 : ans[x][y] + 1;
            q.push([x+1,y]);
            f[x+1][y] = true;
        }
        if(y-1>=0 && !f[x][y-1]) {
            ans[x][y-1] = mat[x][y-1]===0 ? 0 : ans[x][y] + 1;
            q.push([x,y-1]);
            f[x][y-1] = true;
        }
    }
    
    return ans;    
};
