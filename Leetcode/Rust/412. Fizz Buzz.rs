// sol-1 : low level
impl Solution {
    pub fn fizz_buzz(n: i32) -> Vec<String> {
        let mut ans = vec![String::new(); n as usize];
        
        for i in 1..=n as usize {
            if i%15 == 0 {
                ans[i-1] = "FizzBuzz".to_string();
            } else if i%5 == 0 {
                ans[i-1] = String::from("Buzz");
            } else if i%3 == 0 {
                ans[i-1] = String::from("Fizz");
            } else {
                ans[i-1] = i.to_string();
            }
        }
        
        ans
    }
}

// sol-2 : high level
impl Solution {
    pub fn fizz_buzz(n: i32) -> Vec<String> {
        fn find_fizz_buzz(x: i32) -> String {
            if x%15 == 0 {
                String::from("FizzBuzz")
            } else if x%5 == 0 {
                String::from("Buzz")
            } else if x%3 == 0 {
                String::from("Fizz")
            } else {
                x.to_string()
            }
        }
        
        (1..=n)
            .map(find_fizz_buzz)
            .collect::<Vec<String>>()
    }
}
