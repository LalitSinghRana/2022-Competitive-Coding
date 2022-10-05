function relativeSortArray(arr1: number[], arr2: number[]): number[] {
    let m = new Map<number,number>();
    let other: number[] = [];
    arr2.forEach(x => m.set(x,0));
    arr1.forEach(x => {
        if(m.has(x)) m.set(x, (m.get(x) ?? 0) +1);
        else other.push(x);
    });
    
    let ans: number[] = [];
    for(let i=0; i<arr2.length; i++) {
        let cnt: number = m.get(arr2[i]);
        while(cnt--) ans.push(arr2[i]);
    }
    
    other.sort((a,b) => a-b);
    for(let i=0; i<other.length; i++) {
        ans.push(other[i]);
    }
    
    return ans;
};
