// sol-1 : low level 
use std::collections::HashSet;
impl Solution {
    pub fn check_if_exist(arr: Vec<i32>) -> bool {
        let mut hs = HashSet::new();
        for i in 0..arr.len() {
            let found = hs.contains(&(arr[i]*2)) || arr[i]%2 == 0 && hs.contains(&(arr[i]/2));
            hs.insert(arr[i]);
            if found {
                return true;
            }
        };
        false
    }
}

// sol-2 : high level
use std::collections::HashSet;
impl Solution {
    pub fn check_if_exist(arr: Vec<i32>) -> bool {
        let mut hs = HashSet::new();
        arr.iter().any(|&x| {
            let found = hs.contains(&(x*2)) || (x%2 == 0 && hs.contains(&(x/2)));
            hs.insert(x);
            found
        })
    }
}
