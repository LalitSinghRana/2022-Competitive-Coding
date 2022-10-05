impl Solution {
    pub fn sorted_squares(nums: Vec<i32>) -> Vec<i32> {
        let n = nums.len();
        let mut ans = vec![0; n];
        let mut idx = n - 1;
        let (mut l, mut r) = (0, n - 1);
        
        while l < r {
            println!("l = {l}; r = {r}");
            let a = nums[l] * nums[l];
            let b = nums[r] * nums[r];
            if a > b {
                ans[idx] = a;
                l += 1;
            } else {
                ans[idx] = b;
                r -= 1;
            }
            idx -= 1;
        }
        
        ans[idx] = nums[l] * nums[l];
        
        ans
    }
}
