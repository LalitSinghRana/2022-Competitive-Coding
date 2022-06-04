function twoSum(nums: number[], target: number): number[] {
    let myMap = new Map();
    for(let i=0; i<nums.length; i++) {
        if(myMap.has(target - nums[i])) {
            return [myMap.get(target - nums[i]),i];
        }
        myMap.set(nums[i],i);
    }
    return [];
};
