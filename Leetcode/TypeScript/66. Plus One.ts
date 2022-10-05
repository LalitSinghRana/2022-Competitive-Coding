function plusOne(digits: number[]): number[] {
    let c: number = 1;
    for(let i=digits.length-1; i>=0; i--) {
        let t = digits[i] + c;
        c = Math.floor(t/10);
        digits[i] = Math.floor(t%10);
    }
    if(c) digits.unshift(c);
    return digits;
};
