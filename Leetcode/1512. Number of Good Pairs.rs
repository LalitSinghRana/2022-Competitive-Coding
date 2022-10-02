use std::collections::*;
// sol-1: low level
impl Solution {
    pub fn num_identical_pairs(nums: Vec<i32>) -> i32 {
        let mut hm = HashMap::new();
        
        for x in nums {
            *hm.entry(x).or_insert(0) += 1;
        }
        
        let mut ans = 0;
        for val in hm.values() {
            ans += (val * (val-1))/2;
        }
        
        ans
    }
}

// sol-2: high level
impl Solution {
    pub fn num_identical_pairs(nums: Vec<i32>) -> i32 {
        nums
            .into_iter()
            .fold(HashMap::new(), |mut hm, x| {
                *hm.entry(x).or_insert(0) += 1;
                hm
            })
            .values()
            .map(|&val| {
                (val * (val-1))/2
            })
            .sum()
    }
}

// sol-3: low level
impl Solution {
    pub fn num_identical_pairs(nums: Vec<i32>) -> i32 {
        let n = nums.len();
        let mut hm = HashMap::new();
        let mut vec = vec![0; n];
        
        for i in (0..n).rev() {
            vec[i] = *hm.get(&nums[i]).unwrap_or(&0);
            *hm.entry(nums[i]).or_insert(0) += 1;
        }
        
        vec.iter().sum()
    }
}
