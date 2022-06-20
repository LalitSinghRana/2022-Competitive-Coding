// method - 1
function thirdMax(nums: number[]): number {
    nums.sort((a,b) => a-b);
    let s = new Set<number>();
    
    for(let i=0; i<nums.length; i++) {
        s.add(nums[i]);
    }
    let arr: number[] = [...s];
    return arr.length < 3 ? arr[arr.length-1] : arr[arr.length-3];
};


// method - 2
function thirdMax(nums: number[]): number {
    nums.sort((a,b) => a-b);
    let arr: number[] = [];
    arr.push(nums[0]);
    for(let i=1; i<nums.length; i++) if(nums[i] !== arr[arr.length-1]) arr.push(nums[i]);
    return arr.length < 3 ? arr[arr.length-1] : arr[arr.length-3];
};
