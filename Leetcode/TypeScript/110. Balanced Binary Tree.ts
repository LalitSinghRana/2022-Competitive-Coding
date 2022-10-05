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
let flag: boolean = true;

function isBalanced(root: TreeNode | null): boolean {
    flag = true;
    findH(root);
    return flag;
};
    
const findH = (root: TreeNode | null): number => {
    if(!root) return 0;
    
    let l: number = findH(root.left);
    let r: number = findH(root.right);
    
    if(Math.abs(l-r) > 1) flag = false;
    
    return Math.max(l,r) + 1;
}
