impl Solution {
    pub fn final_value_after_operations(operations: Vec<String>) -> i32 {
        let mut ans = 0;
        for str in &operations {
            if str == "++X" || str == "X++" {
                ans += 1;
            } else {
                ans -= 1;
            }
        }
        ans
    }
}
