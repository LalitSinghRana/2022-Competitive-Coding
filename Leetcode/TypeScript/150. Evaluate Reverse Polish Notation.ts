function evalRPN(tokens: string[]): number {
    let s: number[] = [];
    for(let i=0; i<tokens.length; i++) {
        if(tokens[i] !== '+' && tokens[i] !== '-' && tokens[i] !== '*' && tokens[i] !== '/') {
           s.push(Number(tokens[i]));
           continue;
        }
        let y: number = s.pop();
        let x: number = s.pop();
        switch(tokens[i]) {
            case '+' : 
                s.push(x+y);
                break;
            case '-' : 
                s.push(x-y);
                break;
            case '*' : 
                s.push(x*y);
                break;
            case '/' : 
                let r: number = x/y;
                r>=0 ? s.push(Math.floor(r)) : s.push(Math.ceil(r));
                break;
        }
    }
    
    return s[0];
};
