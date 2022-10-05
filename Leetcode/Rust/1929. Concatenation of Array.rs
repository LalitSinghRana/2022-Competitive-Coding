impl Solution {
    pub fn get_concatenation(nums: Vec<i32>) -> Vec<i32> {
        let mut ans = nums.to_vec();
        ans.extend(&nums);
        ans
    }
}
