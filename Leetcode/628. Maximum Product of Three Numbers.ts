function maximumProduct(nums: number[]): number {
    nums.sort((a,b) => a-b);
    console.log(nums);
    let n: number = nums.length;
    let x: number = nums[0]*nums[1]*nums[n-1];
    let y: number = nums[n-1]*nums[n-2]*nums[n-3];
    return Math.max(x,y);
};
