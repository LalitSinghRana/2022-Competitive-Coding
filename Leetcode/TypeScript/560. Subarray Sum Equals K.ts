function subarraySum(nums: number[], k: number): number {
    let m = new Map();
    m.set(0,1);
    let cur=0, ans=0;
    
    for(let i=0; i<nums.length; i++) {
        cur += nums[i];
        if(m.has(cur-k)) ans += m.get(cur-k);
        m.set(cur, (m.get(cur) ?? 0) + 1);
    }
    
    return ans;
};
