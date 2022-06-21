function addStrings(s1: string, s2: string): string {
    if(s1.length < s2.length) [s1, s2] = [s2, s1];
    
    let num1: string[] = s1.split('').reverse();
    let num2: string[] = s2.split('').reverse();
    let arr: string[] = [], c: number = 0;
    
    for(let i=0; i<num2.length; i++) {
        let x: number = parseInt(num1[i]) + parseInt(num2[i]) + c;
        arr.push((x%10).toString());
        c = Math.floor(x/10);
    }
    
    for(let i=num2.length; i<num1.length; i++) {
        let x: number = parseInt(num1[i]) + c;
        arr.push((x%10).toString());
        c = Math.floor(x/10);
    }
    
    if(c) arr.push(c.toString());
    
    let ans: string = arr.reverse().join('');
    return ans;
};
