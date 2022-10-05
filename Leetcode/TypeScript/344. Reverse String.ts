/*
 Do not return anything, modify s in-place instead.
 */
 
 
 // method - 1
function reverseString(s: string[]): void {
    s = s.reverse();
};


// method - 2
function reverseString(s: string[]): void {
    let i: number = 0, j: number = s.length-1;
    while(i<j) {
        [s[i], s[j]] = [s[j], s[i]];
        i++; j--;
    }
};
