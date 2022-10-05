use std::collections::HashMap;
use std::cmp;

impl Solution {
    pub fn find_max_length(nums: Vec<i32>) -> i32 {
        let mut m = HashMap::new();
        let (mut sum, mut mx) = (0, 0);
        
        for i in 0..nums.len() {
            sum += if nums[i] == 1 { 1 } else { -1 };
            
            if sum == 0 {
                mx = cmp::max(mx, i+1);
            } else if m.contains_key(& sum) {
                mx = cmp::max(mx, i - m.get(& sum).unwrap());
            } else {
                m.insert(sum, i);
            }
        }
        
        mx as i32
    }
}
