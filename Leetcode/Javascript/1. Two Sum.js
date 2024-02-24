/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(nums, target) {
    let ans;
    const map = new Map();

    nums.forEach((x,i) => {
        const j = map.get(target - x);
        if (j != undefined) ans = [i,j];
        map.set(x,i)
    });

    return ans;
};
