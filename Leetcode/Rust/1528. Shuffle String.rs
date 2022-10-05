use std::cmp::Ordering;
// sol-1 : low level
impl Solution {
    pub fn restore_string(s: String, indices: Vec<i32>) -> String {
        let mut i = 0 as usize;
        let mut vec = vec![];
        for c in s.chars() {
            vec.push((indices[i], c));
            i += 1;
        }
        
        vec.sort_by(|a,b| a.0.cmp(&b.0));
        
        let mut ans = String::from("");
        for (i,c) in vec {
            ans.push(c);
        }
        
        ans
    }
}

// sol-2 : high level
impl Solution {
    pub fn restore_string(s: String, indices: Vec<i32>) -> String {
        let mut vec = s.chars().zip(indices).collect::<Vec<(char, i32)>>();
        
        vec.sort_by(|a,b| a.1.cmp(&b.1));
        vec.into_iter().map(|x| x.0).collect()
        
    }
}
