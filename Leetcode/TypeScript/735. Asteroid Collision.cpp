function asteroidCollision(asteroids: number[]): number[] {
    let st = [];
    
    for(let i=0; i<asteroids.length; i++) {
        let x = asteroids[i];
        
        if(x < 0 && st.length > 0 && st.at(-1) > 0) {
            let flag = true;
            
            while(st.length > 0 && st.at(-1) > 0) {
                if(Math.abs(x) === st.at(-1)) {
                    flag = false;
                    st.pop();
                    break;
                } else if(Math.abs(x) < st.at(-1)) {
                    flag = false;
                    break;
                } else {
                    st.pop();
                }
            }
            
            if(flag) st.push(x);
        } else {
            st.push(x);
        }
    }
    
    return st;
};
