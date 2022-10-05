// sol-1 : low level
impl Solution {
    pub fn decode(encoded: Vec<i32>, first: i32) -> Vec<i32> {
        let mut ans = vec![];
        ans.push(first);
        
        let mut prev = first;
        for x in encoded {
            prev = x ^ prev;
            ans.push(prev);
        }
        
        ans
    }
}

// sol-2 : high level
impl Solution {
    pub fn decode(encoded: Vec<i32>, first: i32) -> Vec<i32> {
        std::iter::once(&first)
        .chain(encoded.iter())
        .scan(0, |prev, &x| {
            *prev ^= x;
            Some(*prev)
        })
        .collect()
    }
}
