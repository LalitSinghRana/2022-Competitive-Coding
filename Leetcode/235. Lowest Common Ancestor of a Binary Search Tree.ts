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
let ap: TreeNode[] = [];
let aq: TreeNode[] = [];

function lowestCommonAncestor(root: TreeNode | null, p: TreeNode | null, q: TreeNode | null): TreeNode | null {
    find(root, [], p, ap);
    find(root, [], q, aq);
    
    let ans: TreeNode = ap[0];
    for(let i=0; i<Math.min(ap.length, aq.length); i++) if(ap[i] === aq[i]) ans = ap[i];
    
    return ans;
};

let find = (root: TreeNode | null, arr: TreeNode[], t: TreeNode, ans: TreeNode[]) => {
    if(!root) return;
    arr.push(root);
    if(root === t) {
        if(ans === ap) ap = [...arr];
        else aq = [...arr];
    }
    find(root.left, arr, t, ans);
    find(root.right, arr, t, ans);
    arr.pop()
}
