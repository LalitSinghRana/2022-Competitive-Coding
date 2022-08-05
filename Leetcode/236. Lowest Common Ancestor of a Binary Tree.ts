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
let a: TreeNode[], b: TreeNode[];
let P: TreeNode | null, Q: TreeNode | null;

function lowestCommonAncestor(root: TreeNode | null, p: TreeNode | null, q: TreeNode | null): TreeNode | null {
    P = p;
    Q = q;
    
    dfs([], root,);
    
    let ans: TreeNode | null = null;
    for(let i=0; i<Math.min(a.length, b.length); i++) {
        if(a[i] !== b[i]) break;
        ans = a[i];
    }
    
    return ans;
};

const dfs = (stack: TreeNode[], r: TreeNode | null): void => {
    if(!r) return;
    
    stack.push(r)
    if(r === P) a = [...stack];
    if(r === Q) b = [...stack];
    
    dfs(stack, r.left);
    dfs(stack, r.right);
    stack.pop();
}
