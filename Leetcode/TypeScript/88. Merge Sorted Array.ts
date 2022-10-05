function merge(nums1: number[], m: number, nums2: number[], n: number): void {
    let arr: number[] = [];
    let i=0, j=0;
    while(i<m || j<n) {
        if(i>=m || nums1[i] > nums2[j]) {
            arr.push(nums2[j]);
            j++;
        } else {
            arr.push(nums1[i]);
            i++;
        }
    }

    for(let i=0; i<arr.length; i++) {
        nums1[i] = arr[i];
    }
};
