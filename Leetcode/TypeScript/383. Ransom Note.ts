function canConstruct(ransomNote: string, magazine: string): boolean {
    if(ransomNote.length > magazine.length) return false;
    let myMap = new Map();
    
    for(let i=0; i<magazine.length; i++) myMap.set(magazine[i], (myMap.get(magazine[i]) ?? 0) + 1);
    
    for(let i=0; i<ransomNote.length; i++) {
        if(!myMap.get(ransomNote[i])) return false;
        myMap.set(ransomNote[i], myMap.get(ransomNote[i])-1);
    }
    
    return true;
};
