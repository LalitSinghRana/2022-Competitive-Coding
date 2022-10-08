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
    pub fn middle_node(head: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
        let (mut s, mut f) = (&head, &head);
        
        while f.is_some() && f.as_ref().unwrap().next.is_some() {
            s = &s.as_ref().unwrap().next;
            f = &f.as_ref().unwrap().next.as_ref().unwrap().next;
        }
        
        s.clone()
    }
}
