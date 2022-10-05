function search(nums: number[], target: number): number {
    let l: number = 0;
    let r: number = nums.length - 1;
    
    while(l<=r) {
        let m: number = Math.floor(r - (r-l)/2);
        if(nums[m] === target) return m;
        else if(nums[m] < target) l=m+1;
        else r=m-1;
    }
    return -1;
};
