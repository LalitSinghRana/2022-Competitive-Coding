use std::collections::*;
impl Solution {
    pub fn find_kth_largest(nums: Vec<i32>, k: i32) -> i32 {
        let mut heap = BinaryHeap::new();
        for i in 0..nums.len() {
            heap.push(nums[i]);
        }
        
        for i in 1..k {
            heap.pop();
        }
        
        *heap.peek().unwrap()
    }
}
