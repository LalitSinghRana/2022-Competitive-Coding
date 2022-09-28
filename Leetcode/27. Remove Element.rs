// sol-1 : low level
impl Solution {
    pub fn remove_element(nums: &mut Vec<i32>, val: i32) -> i32 {
        let (mut i, mut j): (usize, usize) = (0,0);
        while j < nums.len() {
            if nums[j] != val {
                nums[i] = nums[j];
                i += 1;
            }
            j += 1;
        };
        i as i32
    }
}

// sol-2 : high level
impl Solution {
    pub fn remove_element(nums: &mut Vec<i32>, val: i32) -> i32 {
        *nums = nums
                .iter()
                .filter(|&x| {
                    *x != val
                })
                .cloned()
                .collect::<Vec<i32>>();
        nums.len() as i32
    }
}
