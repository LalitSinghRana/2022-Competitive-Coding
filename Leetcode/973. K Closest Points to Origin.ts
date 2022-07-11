function kClosest(points: number[][], k: number): number[][] {
    let m = new Map<number, number[][]>();
    for(let i=0; i<points.length; i++) {
        let d: number = Math.pow(points[i][0],2) + Math.pow(points[i][1],2);
        let arr: number[][] = m.get(d) ?? [];
        arr.push(points[i]);
        
        m.set(d, arr);
    }
    
    let keys: number[] = [];
    for(let [key, value] of m.entries()) keys.push(key);
    keys.sort((a,b) => a-b);
    
    let ans: number[][] = [];
    for(let i=0; i<keys.length; i++) {
        let arr: number[][] = m.get(keys[i]);
        for(let j=0; j<arr.length; j++) ans.push(arr[j]);
        if(ans.length >= k) break;
    }
    
    return ans;
};
