// sol-1 : low level
impl Solution {
    pub fn array_pair_sum(mut nums: Vec<i32>) -> i32 {
        nums.sort();
        let mut ans = 0;
        for i in 0..nums.len() {
            if i%2 == 0 {
                ans += nums[i];
            }
        }
        ans
    }
}

// sol-2 : high level
impl Solution {
    pub fn array_pair_sum(mut nums: Vec<i32>) -> i32 {
        nums.sort();
        nums.iter().step_by(2).sum()
    }
}
