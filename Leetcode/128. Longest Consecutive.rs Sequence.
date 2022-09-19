use std::{
    collections::HashSet,
    iter::FromIterator,
    cmp::max,
};

impl Solution {
    pub fn longest_consecutive(nums: Vec<i32>) -> i32 {
        let s: HashSet<_> = nums.into_iter().collect();
        
        let mut mx = 0;
        for &(mut x) in s.iter() {
            if !s.contains(&(x-1)) {
                let mut cnt = 0;
                while(s.contains(&x)) {
                    x += 1;
                    cnt += 1;
                }
                mx = max(mx, cnt);
            }
        }
        
        return mx;
    }
}
