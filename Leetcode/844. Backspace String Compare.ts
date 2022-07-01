function backspaceCompare(s: string, t: string): boolean {
    let a: string[] = [];
    let b: string[] = [];
    
    for(let i=0; i<s.length; i++) {
        if(s[i] === '#') a.pop();
        else a.push(s[i]);
    }
    
    for(let i=0; i<t.length; i++) {
        if(t[i] === '#') b.pop();
        else b.push(t[i]);
    }
    
    let x: string = a.join('');
    let y: string = b.join('');
    
    return x===y;
};
