function calPoints(ops: string[]): number {
    let myStack: number[] = [];
    for(let i=0; i<ops.length; i++) {
        if(ops[i] === 'C') myStack.pop();
        else if(ops[i] === 'D') {
            let d: number = 2 * myStack[myStack.length - 1];
            myStack.push(d);
        } else if(ops[i] === '+') {
            let x: number = myStack[myStack.length - 1];
            let y: number = myStack[myStack.length - 2];
            myStack.push(x+y);
        } else {
            let a: number = parseInt(ops[i]);
            myStack.push(a);
        }
    }
    
    let ans: number = 0;
    myStack.forEach(l => ans+=l);
    
    return ans;
};
