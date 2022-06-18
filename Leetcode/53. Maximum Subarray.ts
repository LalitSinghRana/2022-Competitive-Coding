function maxSubArray(nums: number[]): number {
    let mth: number = nums[0], msf: number = nums[0];
    
    for(let i=1; i<nums.length; i++) {
        mth += nums[i];
        if(mth <= nums[i]) mth = nums[i];
        if(msf < mth) msf = mth;
    }
    
    return msf;
};
