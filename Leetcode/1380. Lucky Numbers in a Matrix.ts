function luckyNumbers (matrix: number[][]): number[] {
    let lucky: number[] = [];
    for(let i=0; i<matrix.length; i++) {
        let num: number = Number.MAX_SAFE_INTEGER;
        let col: number = -1;
        for(let j=0; j<matrix[i].length; j++) {
            if(matrix[i][j] < num) {
                num = matrix[i][j];
                col = j;
            }
        }
        
        let flag: boolean = true;
        for(let k=0; k<matrix.length; k++) {
            if(matrix[k][col] > num) flag = false;
        }
        
        if(flag) lucky.push(num);
    }
    
    return lucky;
};
