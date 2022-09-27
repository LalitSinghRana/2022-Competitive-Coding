impl Solution {
    pub fn duplicate_zeros(arr: &mut Vec<i32>) {
        let n = arr.len();
        let mut ans = vec![0; n];
        let (mut i, mut j) = (0,0);
        
        while(i<n) {
            if(arr[j] == 0) {
                i += 2;
            } else {
                ans[i] = arr[j];
                i += 1;
            }
            j += 1;
        }
        
        *arr = ans;
    }
}
