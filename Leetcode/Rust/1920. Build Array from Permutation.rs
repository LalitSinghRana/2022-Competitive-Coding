// sol-1 : low level
impl Solution {
    pub fn build_array(nums: Vec<i32>) -> Vec<i32> {
        let mut ans = vec![0; nums.len()];
        let mut ans2: Vec<i32> = vec![];
        
        for i in 0..nums.len() {
            ans[i] = nums[nums[i] as usize];
        }
        
        ans
    }
}

// sol-2 : high level
impl Solution {
    pub fn build_array(nums: Vec<i32>) -> Vec<i32> {
        (0..nums.len()).map(|i| {
            nums[nums[i] as usize]
        }).collect()
    }
}
