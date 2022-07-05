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
let ans = 0;
function diameterOfBinaryTree(root: TreeNode | null): number {
    ans = 0;
    dfs(root);
    return ans-1;
};

const dfs = (root: TreeNode | null): number => {
    if(!root) return 0;
    let l = dfs(root.left);
    let r = dfs(root.right);
    ans = Math.max(ans, l+r+1);
    return Math.max(l,r) +1;
}
