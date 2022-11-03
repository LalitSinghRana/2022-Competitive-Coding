function maximalSquare(matrix: string[][]): number {
    let A = [], n = matrix.length, m = matrix[0].length, ans = 0;
    
    for(let i=0; i<n; i++) {
        A.push([]);
        for(let j=0; j<m; j++) {
            A[i].push(Number(matrix[i][j]));
            ans = Math.max(ans, A[i][j]);
        }
    }
    
    for(let i=1; i<n; i++) {
        for(let j=1; j<m; j++) {
            if(A[i][j]) A[i][j] = 1 + Math.min(A[i-1][j], A[i-1][j-1], A[i][j-1]);
            ans = Math.max(ans, A[i][j]);
        }
    }
    
    return ans*ans;
};
