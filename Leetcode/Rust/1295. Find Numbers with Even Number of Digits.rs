impl Solution {
    pub fn find_numbers(nums: Vec<i32>) -> i32 {
        let mut ans = 0;
        
        for mut x in nums {
            let mut cnt = 0;
            while x > 0 {
                x /= 10;
                cnt += 1;
            }
            
            if cnt%2 == 0 {
                ans += 1;
            }
        }
        
        ans
    }
}
