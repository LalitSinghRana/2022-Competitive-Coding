// sol-1 : low level
impl Solution {
    pub fn defang_i_paddr(address: String) -> String {
        let mut ans = String::new();
        for c in address.chars() {
            if c == '.' {
                ans += "[.]";
            } else {
                ans.push(c);
            }
        }
        ans
    }
}

// sol-2 : high level in built funtion
impl Solution {
    pub fn defang_i_paddr(address: String) -> String {
        address.replace(".", "[.]")
    }
}

// sol-3 : high level
impl Solution {
    pub fn defang_i_paddr(address: String) -> String {
        address.chars().map(|c| {
            if c == '.' {
                "[.]".to_string()
            } else {
                c.to_string()
            }
        }).collect()
    }
}
