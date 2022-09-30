use std::collections::*;
impl Solution {
    pub fn num_jewels_in_stones(jewels: String, stones: String) -> i32 {
        let mut hs_j: HashSet<char> = jewels.chars().collect();        
        let mut ans = 0;
        
        for c in stones.chars() {
            if hs_j.contains(&c) {
                ans += 1;
            }
        }
        ans
    }
}
