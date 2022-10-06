// sol-1 : low level
impl Solution {
    pub fn decompress_rl_elist(nums: Vec<i32>) -> Vec<i32> {
        let mut ans = vec![];
        for i in (0..nums.len()).step_by(2) {
            for j in 0..nums[i] {
                ans.push(nums[i+1]);
            }
        }
        ans
    }
}

// sol-2 : high level
impl Solution {
    pub fn decompress_rl_elist(nums: Vec<i32>) -> Vec<i32> {
        nums.chunks_exact(2)
            .flat_map(|v| vec![v[1]; v[0] as usize])
            .collect()
    }
}
