function threeSum(nums: number[]): number[][] {
    let ans: number[][] = [];
    nums.sort((a,b) => a-b);
    
    for(let i=0; i<nums.length; i++) {
        if (i > 0 && nums[i] === nums[i - 1]) {
            continue;
        }
        let j=i+1, k=nums.length-1;
        while(j<k) {
            if(nums[j] + nums[k] === -nums[i]) {
                let t: number[] = [nums[i], nums[j], nums[k]];
                t.sort((a,b) => a-b);
                ans.push(t);
                k--; j++;
            } 
            else if(nums[j] + nums[k] > -nums[i]) k--;
            else j++;
        }
    }
    
    ans.sort((a,b) => {
        if(a[0] === b[0] && a[1] === b[1]) return a[2]-b[2];
        else if(a[0] === b[0]) return a[1]-b[1];
        else return a[0]-b[0];
    });
    
    if(!ans.length) return [];
    
    let res: number[][] = [];
    res.push(ans[0]);
    for(let i=1; i<ans.length; i++) {
        if(ans[i][0] === res[res.length-1][0]
            && ans[i][1] === res[res.length-1][1]
           && ans[i][2] === res[res.length-1][2]
          ) continue;
        res.push(ans[i]);
    }
    
    return res;
};
