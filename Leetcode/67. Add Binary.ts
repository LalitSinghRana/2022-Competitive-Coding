function addBinary(a: string, b: string): string {
    let s: string = "";
    
    a = a.split("").reverse().join("");
    b = b.split("").reverse().join("");
    
    if(a.length > b.length) [a,b] = [b,a];
    
    let c: number = 0;
    
    for(let i: number = 0; i<a.length; i++) {
        let x: number = parseInt(a[i]);
        let y: number = parseInt(b[i]);
        s += ((x+y+c)%2).toString();
        c = Math.floor((x+y+c)/2);
    }
    
    for(let i: number = a.length; i<b.length; i++) {
        let y: number = parseInt(b[i]);
        s += ((y+c)%2).toString();
        c = Math.floor((y+c)/2);
    }
    
    if(c > 0) s += c.toString();
    
    return s.split("").reverse().join("");
};
