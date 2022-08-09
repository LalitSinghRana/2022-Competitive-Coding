/**
 Do not return anything, modify nums in-place instead.
 */
function sortColors(nums: number[]): void {
    let red: number = 0, white: number = 0;
    for(let i=0; i<nums.length; i++) {
        if(nums[i] === 0) red++;
        else if(nums[i] === 1) white++;
    }

    for(let i=0; i<nums.length; i++) {
        if(i < red) nums[i] = 0;
        else if(i < red+white) nums[i] = 1;
        else nums[i] = 2;
    }
};
