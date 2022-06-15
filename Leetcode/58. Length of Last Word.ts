function lengthOfLastWord(s: string): number {
    let arr: string[] = s.split("").reverse();
    while(arr[0] === " ") {
        arr.shift();
    }
    
    let i: number = 0;
    while(arr[i] !== " " && i<arr.length) i++;
    
    return i;
};
