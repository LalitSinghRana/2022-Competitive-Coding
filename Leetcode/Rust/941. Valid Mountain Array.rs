impl Solution {
    pub fn valid_mountain_array(arr: Vec<i32>) -> bool {
        let (mut i, n) = (1, arr.len());
        
        if n < 3 || arr[0] >= arr[1] {
            return false;
        }
        
        while i < n {
            if arr[i-1] == arr[i] {
                return false;
            } else if arr[i-1] > arr[i] {
                break;
            }
            i += 1;
        }
        
        if(i >= n) {
            return false;
        }
        
        while i < n{
            if arr[i-1] <= arr[i] {
                return false;
            }
            i += 1;
        }
        
        true
    }
}
