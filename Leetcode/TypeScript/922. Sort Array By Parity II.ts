function sortArrayByParityII(nums: number[]): number[] {
    let odd: number[] = [];
    let even: number[] = [];
    let ans: number[] = [];
    nums.forEach(a => {
        a%2 ? odd.push(a) : even.push(a);
    })
    
    for(let i=0; i<odd.length; i++) {
        ans.push(even[i]);
        ans.push(odd[i]);
    }
    
    return ans;
};
