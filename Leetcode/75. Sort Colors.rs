impl Solution {
    pub fn sort_colors(nums: &mut Vec<i32>) {
        let (mut cnt0, mut cnt1, mut cnt2) = (0,0,0);
        for i in 0..nums.len() {
            if nums[i] == 0 { cnt0 += 1; }
            else if nums[i] == 1 { cnt1 += 1; }
            else { cnt2 += 1; }
        }
        
        for i in 0..nums.len() {
            if i < cnt0 {
                nums[i] = 0;
            } else if i < cnt0+cnt1 {
                nums[i] = 1;
            } else {
                nums[i] = 2;
            }
        }
    }
}
