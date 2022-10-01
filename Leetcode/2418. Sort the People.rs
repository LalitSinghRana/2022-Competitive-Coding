// sol-1 : using sort_by
impl Solution {
    pub fn sort_people(names: Vec<String>, heights: Vec<i32>) -> Vec<String> {
        let mut vec: Vec<(i32, &String)> = vec![];
        for i in 0..names.len() {
            vec.push((heights[i], &names[i]));
        }
        
        vec.sort_by(|a,b| {
            b.0.partial_cmp(&a.0).unwrap()
        });
        
        vec.into_iter().map(|(x,y)| y.to_string()).collect::<Vec<String>>()
    }
}

// sol-2: using BTreeMap
use std::collections::*;
impl Solution {
    pub fn sort_people(names: Vec<String>, heights: Vec<i32>) -> Vec<String> {
        let mut btm = BTreeMap::new();
        for i in 0..names.len() {
            btm.insert(heights[i], &names[i]);
        }
        
        let mut ans: Vec<String> = vec![];
        for (k,v) in &btm {
            ans.push(v.to_string());
        }
        ans.reverse();
        return ans;
    }
}
