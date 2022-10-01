impl Solution {
    pub fn sort_sentence(s: String) -> String {
        let mut vec = vec!["".to_string(); 10];
        
        for str in s.split(" ") {
            let i: usize = str.chars().last().unwrap().to_digit(10).unwrap() as usize;
            vec[i] = str.chars().skip(0).take(str.len() - 1).collect();
        }
        
        let mut ans =  String::from("");
        for str in vec {
            ans.push_str(&str);
            ans.push(' ');
        }
        ans.trim().to_string()
    }
}
