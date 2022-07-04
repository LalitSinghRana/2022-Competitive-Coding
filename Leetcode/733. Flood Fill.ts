function floodFill(image: number[][], sr: number, sc: number, color: number): number[][] {
    let old: number = image[sr][sc];
    if(old === color) return image;
    
    let q: number[][] = [];
    q.push([sr,sc]);
    while(q.length > 0) {
        let [a, b] = q.shift();
        if(a+1 < image.length && image[a+1][b] === old) q.push([a+1,b]);
        if(a-1 >= 0 && image[a-1][b] === old) q.push([a-1,b]);
        if(b+1 < image[a].length && image[a][b+1] === old) q.push([a,b+1]);
        if(b-1 >= 0 && image[a][b-1] === old) q.push([a,b-1]);
        image[a][b] = color;
    }
    
    return image;
};
