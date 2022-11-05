impl Solution {
    pub fn rotate(A: &mut Vec<Vec<i32>>) {
        A.reverse();
        
        for i in 0..A.len() {
            for j in 0..i {
                let t = A[i][j];
                A[i][j] = A[j][i];
                A[j][i] = t;
            }
        }
    }
}
