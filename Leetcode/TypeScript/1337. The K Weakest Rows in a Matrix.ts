function kWeakestRows(mat: number[][], k: number): number[] {
    let arr: number[][] = [];
    for(let i=0; i<mat.length; i++) {
        let temp: number = 0;
        for(let j=0; j<mat[i].length; j++) {
            if(mat[i][j]) temp++;
        }
        arr.push([temp, i]);
    }
    
    arr.sort((a,b) => {
        return a[0] === b[0] ? a[1]-b[1] : a[0]-b[0];
    });
    
    let ans: number[] = [];
    let j: number = 0;
    while(j<k) ans.push(arr[j++][1]);
    
    return ans;
};
