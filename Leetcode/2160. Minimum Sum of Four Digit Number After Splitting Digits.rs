impl Solution {
    pub fn minimum_sum(mut num: i32) -> i32 {
        let mut v = vec![];
        while num > 0 {
            v.push(num%10);
            num /= 10;
        }
        v.sort();
        (v[0]*10 + v[3]) + (v[1]*10 + v[2])
    }
}
