// sol-1 : low level
impl Solution {
    pub fn interpret(command: String) -> String {
        let mut ans: String = String::new();
        let mut prev = ' ';
        for c in command.chars() {
            match (c, prev) {
                ('G', _) => ans.push('G'),
                (')', '(') => ans.push('o'),
                (')', 'l') => ans.push_str("al"),
                _ => prev = c,
            }
        }
        
        ans
    }
}

// sol-1 : high level
impl Solution {
    pub fn interpret(command: String) -> String {
        command.replace("()", "o").replace("(al)", "al")
    }
}
