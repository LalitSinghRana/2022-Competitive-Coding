function largestSumAfterKNegations(nums: number[], k: number): number {
    nums.sort((a,b) => a-b);
    let i: number = 0, sum: number = 0;
    
    while(nums[i] < 0 && k) {
        nums[i] *= -1;
        i++;
        k--;
    }
    nums.sort((a,b) => a-b);
    
    if(k%2) nums[0] *= -1;
    
    nums.forEach(x => sum += x);
    return sum;
};
