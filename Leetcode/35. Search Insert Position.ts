function searchInsert(nums: number[], target: number): number {
    let l: number = 0, r: number = nums.length-1, m: number = 0;
    
    while(l<r) {
        m = Math.floor((l+r)/2);
        if(nums[m] === target) return m;
        else if(nums[m] > target) r = m-1;
        else l = m+1;
    }
    
    return target<=nums[l] ? l : l+1;
};
