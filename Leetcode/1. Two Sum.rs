use std::collections::HashMap;

impl Solution {
    pub fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32> {
        let mut m:HashMap<i32, i32> = HashMap::new();
        
        for (i, &x) in nums.iter().enumerate() {
            match m.get(&(target - x)) {
                Some(&j) => return vec![j, i as i32],
                None => m.insert(x, i as i32),
            };
        }
        
        return vec![];
    }
}
