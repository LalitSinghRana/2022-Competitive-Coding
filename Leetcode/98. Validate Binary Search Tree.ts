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

function isValidBST(root: TreeNode | null): boolean {
    return validate(root, Math.pow(-2,31)-1, Math.pow(2,31));
};

const validate = (root: TreeNode | null, l: number, r: number): boolean => {
    if(!root) return true;
    
    if(root.val<=l || root.val>=r) return false;
    
    return validate(root.left, l, root.val) && validate(root.right, root.val, r);
}
