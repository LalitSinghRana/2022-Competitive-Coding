function diagonalSum(mat: number[][]): number {
    let ans: number = 0, n: number = mat.length;
    
    for(let i=0; i<n; i++) {
        ans += mat[i][i] + mat[i][n-1-i];
    }
    
    if(n%2) {
        let m: number = Math.floor(n/2);
        ans -= mat[m][m];
    }
    
    return ans;
};
