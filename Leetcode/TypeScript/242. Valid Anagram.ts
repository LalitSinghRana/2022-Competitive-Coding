function isAnagram(s: string, t: string): boolean {
    if(s.length !== t.length) return false;
    let myMap = new Map();
    
    for(let i: number = 0; i<s.length; i++) {
        myMap.set(s[i], (myMap.get(s[i]) ?? 0) + 1);
    }
    
    for(let i: number = 0; i<t.length; i++) {
        if(!myMap.get(t[i])) return false;
        else myMap.set(t[i], (myMap.get(t[i]) ?? 0) - 1);
    }
    
    return true;
};
