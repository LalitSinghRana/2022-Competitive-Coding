// sol-1 : using vec and indexs
impl Solution {
    pub fn running_sum(nums: Vec<i32>) -> Vec<i32> {
        let mut ans: Vec<i32> = vec![];
        ans.push(nums[0]);
        
        for i in 1..nums.len() {
            ans.push(nums[i] + ans[i-1]);
        }
        
        ans
    }
}

// sol-2 : using vec and indexs
impl Solution {
    pub fn running_sum(nums: Vec<i32>) -> Vec<i32> {
        let n = nums.len();
        let mut ans: Vec<i32> = vec![0; n];
        ans[0] = nums[0];
        
        for i in 1..n {
            ans[i] = nums[i] + ans[i-1];
        }
        
        ans
    }
}

// sol-3 : using funtional programing
impl Solution {
    pub fn running_sum(nums: Vec<i32>) -> Vec<i32> {
        let mut prev_sum = 0;
        nums.into_iter()
            .map(|x| {
                prev_sum += x;
                prev_sum
            })
            .collect::<Vec<i32>>()
    }
}
