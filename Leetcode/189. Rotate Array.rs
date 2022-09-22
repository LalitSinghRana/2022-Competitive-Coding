impl Solution {
    pub fn rotate(nums: &mut Vec<i32>, k: i32) {
        let mut x = k as usize % nums.len();
        nums.reverse();
        nums[0..x].reverse();
        nums[x..].reverse();
    }
}
