impl Solution {
    pub fn smaller_numbers_than_current(nums: Vec<i32>) -> Vec<i32> {
        let mut nums2 = nums.to_vec();
        nums2.sort();
        
        let mut ans = vec![];
        for &x in &nums {
            for i in 0..nums2.len() {
                if x == nums2[i] {
                    ans.push(i as i32);
                    break;
                }
            }
        }
        ans
    }
}
