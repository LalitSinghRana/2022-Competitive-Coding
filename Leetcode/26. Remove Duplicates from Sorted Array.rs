// sol-1 : low level
impl Solution {
    pub fn remove_duplicates(nums: &mut Vec<i32>) -> i32 {
        let mut j = 0 as usize;
        
        for i in 1..nums.len() {
            if nums[i] != nums[j] {
                j += 1;
                nums[j] = nums[i];
            }
        }
        (j+1) as i32
    }
}

// sol-2 : high level
impl Solution {
    pub fn remove_duplicates(nums: &mut Vec<i32>) -> i32 {
        let mut prev = i32::MIN;
        nums.retain(|x| {
            if *x == prev {
                false
            } else {
                prev = *x;
                true
            }
        });
        nums.len() as i32
    }
}
