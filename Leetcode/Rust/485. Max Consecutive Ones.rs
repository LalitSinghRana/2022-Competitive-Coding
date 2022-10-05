use std::cmp;

// sol-1 : low level
impl Solution {
    pub fn find_max_consecutive_ones(nums: Vec<i32>) -> i32 {
        let (mut mx, mut cur) = (0, 0);
        
        for i in 0..nums.len() {
            if nums[i] == 0 {
                mx = cmp::max(mx, cur);
                cur = 0;
            } else {
                cur += 1;
            }
        }
        
        mx = cmp::max(mx, cur);
        mx
    }
}

// sol-2 : low level
impl Solution {
    pub fn find_max_consecutive_ones(nums: Vec<i32>) -> i32 {
        let (mut mx, mut cur) = (0, 0);
        
        for x in nums {
            if x == 0 {
                mx = cmp::max(mx, cur);
                cur = 0;
            } else {
                cur += 1;
            }
        }
        
        mx = cmp::max(mx, cur);
        return mx;
    }
}
