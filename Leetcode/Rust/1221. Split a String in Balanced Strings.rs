// sol-1 : low level
impl Solution {
    pub fn balanced_string_split(s: String) -> i32 {
        let (mut cnt, mut ans) = (0, 0);
        for c in s.chars() {
            if c == 'L' {
                cnt -= 1;
            } else {
                cnt += 1;
            }

            if cnt == 0 {
                ans += 1;
            }
        }
        ans
    }
}

// sol-2 : high level
impl Solution {
    pub fn balanced_string_split(s: String) -> i32 {
        s.chars()
            .fold((0,0), |(mut cnt, mut ans), c| {
                cnt += if c == 'L' {-1} else {1};
                ans += (cnt == 0) as i32;
                (cnt, ans)
            })
            .1
    }
}
