impl Solution {
    pub fn height_checker(heights: Vec<i32>) -> i32 {
        let mut expected = heights.to_vec();
        expected.sort_unstable();
        let mut cnt = 0;
        
        for i in 0..heights.len() {
            if heights[i] != expected[i] { cnt += 1; }
        }
        
        cnt
    }
}
