// sol-1 : low level
impl Solution {
    pub fn cells_in_range(s: String) -> Vec<String> {
        let mut ans = vec![];
        let vec = s.chars().collect::<Vec<char>>();
        
        for col in vec[0]..=vec[3] {
            for row in vec[1]..=vec[4] {
                ans.push(format!("{col}{row}"));
            }
        }
        
        ans
    }
}

// sol-2 : high level
impl Solution {
    pub fn cells_in_range(s: String) -> Vec<String> {
        let vec = s.chars().collect::<Vec<char>>();
        
        (vec[0]..=vec[3])
            .flat_map(|col| {
                (vec[1]..=vec[4]).map(move |row| format!("{col}{row}"))
            })
            .collect()
    }
}
