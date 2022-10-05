let m = new Map<number, number[]>();
let s = new Set<number>();
let f = true;

function canFinish(num: number, arr: number[][]): boolean {
    m = new Map<number, number[]>();
    s = new Set<number>();
    f = true;
    
    for(let i=0; i<num; i++) m.set(i, []);
    for(let i=0; i<arr.length; i++) m.get(arr[i][0]).push(arr[i][1])
    for(let i=0; i<num; i++) {
        dfs(i);
        if(!f) break;
    }
    
    return f;
};
    
const dfs = (k: number) => {
    if(s.has(k)) f = false;
    if(!f || m.get(k) === []) return;
    
    s.add(k);
    while(m.get(k).length) {
        dfs(m.get(k)[0]);
        if(!f) return;
        m.get(k).shift();
    }
    s.delete(k);
}
