function minimumAbsDifference(arr: number[]): number[][] {
    arr.sort((a,b) => a-b);
    let m = new Map<number, number[][]>();
    
    for(let i=1; i<arr.length; i++) {
        let d: number = arr[i] - arr[i-1];
        let a: number[][] = m.get(d) ?? [];
        a.push([arr[i-1], arr[i]])
        m.set(d, a);
    }
    
    let s: number = Number.MAX_SAFE_INTEGER;
    
    for(let [key, value] of m.entries()) {
        if(key < s) s = key;
    }
    
    return m.get(s);
};
