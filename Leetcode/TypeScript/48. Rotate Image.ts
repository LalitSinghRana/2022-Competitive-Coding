function rotate(A: number[][]): void {
    A.reverse();
    
    for(let i=0; i<A.length; i++) {
        for(let j=0; j<i; j++) [A[i][j], A[j][i]] = [A[j][i], A[i][j]];
    }
};
