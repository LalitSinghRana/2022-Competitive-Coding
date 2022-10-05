function transpose(matrix: number[][]): number[][] {
    let ans: number[][] = [];
    for(let j=0; j<matrix[0].length; j++) {
        ans.push([]);
        for(let i=0; i<matrix.length; i++) ans[j].push(matrix[i][j]);
    }
    return ans;
};
