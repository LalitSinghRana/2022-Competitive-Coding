/**
 Do not return anything, modify nums in-place instead.
 */
function moveZeroes(nums: number[]): void {
    let j: number = 0;
    for(let i=0; i<nums.length; i++) {
        if(nums[i]) nums[j++] = nums[i];
    }
    
    while(j<nums.length) nums[j++] = 0;
};
