// sol-1 : low level
impl Solution {
    pub fn target_indices(mut nums: Vec<i32>, target: i32) -> Vec<i32> {
        let mut ans: Vec<i32> = vec![];
        
        nums.sort();
        
        for (i, &x) in nums.iter().enumerate() {
            if x == target {
                ans.push(i as i32);
            }
        }
        
        ans
    }
}


// sol-2 : high level
impl Solution {
    pub fn target_indices(mut nums: Vec<i32>, target: i32) -> Vec<i32> {
        nums.sort();
        
        nums
            .iter()
            .enumerate()
            .filter(|(_,&x)| {
                x == target
            })
            .map(|(i,_)| i as i32)
            .collect()
    }
}
