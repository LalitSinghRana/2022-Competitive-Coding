function removeDuplicates(nums: number[]): number {
    let i:number = 0, j:number = 1;
    for(j; j<nums.length; j++) {
        if(nums[j] !== nums[i]) {
            nums[i+1] = nums[j];
            i++;
        }
    }
    return i+1;
};
