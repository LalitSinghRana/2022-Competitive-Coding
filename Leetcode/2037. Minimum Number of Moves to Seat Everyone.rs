// sol-2 : low level
impl Solution {
    pub fn min_moves_to_seat(mut seats: Vec<i32>, mut students: Vec<i32>) -> i32 {
        seats.sort();
        students.sort();
        
        let mut ans = 0;
        
        for i in 0..seats.len() {
            ans += (students[i] - seats[i]).abs();
        }
        
        ans
    }
}

// sol-2 : high level
impl Solution {
    pub fn min_moves_to_seat(mut seats: Vec<i32>, mut students: Vec<i32>) -> i32 {
        seats.sort();
        students.sort();
        
        let mut ans = 0;
        
        students
            .iter()
            .zip(seats.iter())
            .for_each(|(student, seat)| {
                ans += (student - seat).abs();
            });
        
        ans
    }
}
