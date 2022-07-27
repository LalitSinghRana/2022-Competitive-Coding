function search(nums: number[], t: number): number {
    let l: number = 0, r: number = nums.length-1, m: number;
    while(l<=r) {
        let m: number = Math.floor((l+r)/2);
        if(nums[m] === t) return m;
        else if(nums[l] <= nums[m]) {
            if(t >= nums[l] && t <= nums[m]) r = m-1;
            else l = m+1;
        }
        else {
            if(t >= nums[m] && t <= nums[r]) l = m+1;
            else r = m-1;
        }
    }
    
    return -1;
};
