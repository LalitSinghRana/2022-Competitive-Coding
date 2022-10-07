// Definition for singly-linked list.
// #[derive(PartialEq, Eq, Clone, Debug)]
// pub struct ListNode {
//   pub val: i32,
//   pub next: Option<Box<ListNode>>
// }
// 
// impl ListNode {
//   #[inline]
//   fn new(val: i32) -> Self {
//     ListNode {
//       next: None,
//       val
//     }
//   }
// }
impl Solution {
    pub fn get_decimal_value(head: Option<Box<ListNode>>) -> i32 {
        let mut vec = vec![];
        let mut cur = &head;
        
        while let Some(node) = cur {
            vec.push(node.val);
            cur = &node.next;
        }

        let mut ans = 0;
        for i in 0..vec.len() {
            ans += 2_i32.pow(i as u32) * vec[&vec.len() - 1 - i];
        }
        
        ans
    }
}
