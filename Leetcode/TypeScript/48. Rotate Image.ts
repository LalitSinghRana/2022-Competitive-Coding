function rotate(A: number[][]): void {
    let n = A.length;
    
    for(let i=0; i<n; i++) {
        let l=0, r=i;
        while(l<r) {
            [A[r][l], A[l][r]] = [A[l][r], A[r][l]];
            l++; r--;
        }
        
        l=i; r=n-1;
        while(i && l<r) {
            [A[r][l], A[l][r]] = [A[l][r], A[r][l]];
            l++; r--;
        }
    }

    for(let i=0; i<n; i++) A[i].reverse();
};
