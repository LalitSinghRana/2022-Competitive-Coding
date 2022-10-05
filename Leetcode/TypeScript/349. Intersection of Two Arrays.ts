function intersection(nums1: number[], nums2: number[]): number[] {
    nums1.sort((a,b) => a-b);
    nums2.sort((a,b) => a-b);
    
    let i: number = 0, j: number = 0, ans: number[] = [];
    
    while(i<nums1.length && j<nums2.length) {
        if(nums1[i] === nums2[j]) {
            let t: number = nums1[i];
            ans.push(t);
            while(nums1[i] === t) i++;
            while(nums2[j] === t) j++;
        } else if(nums1[i] < nums2[j]) i++;
        else j++;
    }
    
    return ans;
};
