function isValid(s: string): boolean {
    let myStack: string[] = [];
    
    for(let i: number = 0; i<s.length; i++) {
        let x: string = s[i];
        if(x === '(' || x === '{' || x === '[') myStack.push(x);
        else if(x === ')') {
            if(myStack[myStack.length - 1] === '(') myStack.pop();
            else return false;
        } else if(x === '}') {
            if(myStack[myStack.length - 1] === '{') myStack.pop();
            else return false;
        } else if(x === ']') {
            if(myStack[myStack.length - 1] === '[') myStack.pop();
            else return false;
        }
    }
    
    if(!myStack.length) return true;
    return false;
};
