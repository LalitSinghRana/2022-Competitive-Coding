function canJump(nums: number[]): boolean {
    let n = nums.length, goal = n-1;
    
    for(let i=n-2; i>=0; i--) {
        if(i + nums[i] >= goal) goal = i;
    }
    
    return goal == 0;
};
