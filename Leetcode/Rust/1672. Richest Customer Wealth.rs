// sol-1 : using for loops
use std::cmp;
impl Solution {
    pub fn maximum_wealth(accounts: Vec<Vec<i32>>) -> i32 {
        let mut mx = 0;
        for i in 0..accounts.len() {
            let mut cur = 0;
            for j in 0..accounts[i].len() {
                cur += accounts[i][j];
            }
            mx = cmp::max(mx, cur);
        }
        mx
    }
}

// sol-2 : using funtional
impl Solution {
    pub fn maximum_wealth(accounts: Vec<Vec<i32>>) -> i32 {
        accounts
            .into_iter()
            .map(|arr| {
                arr.into_iter().sum()
            })
            .max()
            .unwrap()
    }
}
