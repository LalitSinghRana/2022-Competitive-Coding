function productExceptSelf(nums: number[]): number[] {
    let prod: number = 1;
    for(let i=0; i<nums.length; i++) prod *= nums[i];
    
    let ans: number[] = [];
    for(let i=0; i<nums.length; i++) {
        if(!nums[i])  {
            let t: number = 1;
            for(let j=0; j<nums.length; j++) if(i!==j) t *= nums[j];
            ans.push(t);
        } else ans.push(prod/nums[i]);
    }
    
    return ans;
};
