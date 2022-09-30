// sol-1 : high level
impl Solution {
    pub fn most_words_found(sentences: Vec<String>) -> i32 {
        sentences.iter()
        .map(|str| str.split(' ').count())
        .max()
        .unwrap() as i32
    }
}

// sol-2 : low level
use std::cmp;
impl Solution {
    pub fn most_words_found(sentences: Vec<String>) -> i32 {
        let mut mx = i32::MIN;
        for str in &sentences {
            mx = cmp::max(mx, str.split(' ').count() as i32);
        }
        mx
    }
}
