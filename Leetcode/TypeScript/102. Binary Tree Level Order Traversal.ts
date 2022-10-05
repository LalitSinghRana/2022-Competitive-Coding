/**
 * Definition for a binary tree node.
 * class TreeNode {
 *     val: number
 *     left: TreeNode | null
 *     right: TreeNode | null
 *     constructor(val?: number, left?: TreeNode | null, right?: TreeNode | null) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.left = (left===undefined ? null : left)
 *         this.right = (right===undefined ? null : right)
 *     }
 * }
 */

function levelOrder(root: TreeNode | null): number[][] {
    if(!root) return [];
    let q: TreeNode[] = [];
    let ans: number[][] = [];
    q.push(root);
    
    while(q.length) {
        let n: number = q.length;
        let t: number[] = [];
        while(n--) {
            t.push(q[0].val);
            let r: TreeNode = q.shift();
            if(r.left) q.push(r.left);
            if(r.right) q.push(r.right);
        }
        ans.push(t);
    }
    
    return ans;
};
