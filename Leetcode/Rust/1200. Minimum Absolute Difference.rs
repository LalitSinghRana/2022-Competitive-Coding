use std::cmp;
use std::collections::*;
impl Solution {
    pub fn minimum_abs_difference(arr: Vec<i32>) -> Vec<Vec<i32>> {
        let mut arr2 = arr.to_vec();
        arr2.sort();
        
        let mut map:BTreeMap<i32,Vec<Vec<i32>>> = BTreeMap::new();
        for i in 1..arr2.len() {
            let key = arr2[i]-arr2[i-1];
            let mut val = [arr2[i-1], arr2[i]].to_vec();
            
            match map.get_mut(&key) {
                Some(temp) => {
                    temp.push(val);
                },
                None => {
                    map.insert(key, vec![val]);
                }
            }
        }
        
        map.values().next().unwrap().to_vec()
    }
}
