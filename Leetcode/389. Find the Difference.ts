// method - 1
function findTheDifference(s: string, t: string): string {
    s = s.split('').sort().join('');
    t = t.split('').sort().join('');
    
    for(let i=0; i<s.length; i++) {
        if(s[i] !== t[i]) return t[i];
    }
    
    return t[t.length-1];
};


// method - 2
function findTheDifference(s: string, t: string): string {
    let ms = new Map<string,number>();
    let mt = new Map<string,number>();
    
    for(let i=0; i<s.length; i++) {
        ms.set(s[i], (ms.get(s[i]) ?? 0) +1);
        mt.set(t[i], (mt.get(t[i]) ?? 0) +1);
    }
    
    mt.set(t[t.length-1], (mt.get(t[t.length-1]) ?? 0) +1);
    
    for(let [key, value] of mt.entries()) {
        console.log(key, value);
        if(value !== ms.get(key)) return key;
    }
};
