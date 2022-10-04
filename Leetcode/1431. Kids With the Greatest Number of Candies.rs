// sol-1 : low level
use std::cmp;
impl Solution {
    pub fn kids_with_candies(candies: Vec<i32>, extra_candies: i32) -> Vec<bool> {
        let mut mx = i32::MIN;
        for &x in &candies {
            mx = cmp::max(mx, x);
        }
        
        let mut ans = vec![];
        for &x in &candies {
            ans.push(x + extra_candies >= mx);
        }
        
        ans
    }
}


// sol-2 : high level
impl Solution {
    pub fn kids_with_candies(candies: Vec<i32>, extra_candies: i32) -> Vec<bool> {
        let mx = *candies.iter().max().unwrap();
        candies.iter().map(|&x| {
            x + extra_candies >= mx
        }).collect()
    }
}
