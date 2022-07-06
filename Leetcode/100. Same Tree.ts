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

let ap: Number[] = [];
let aq: Number[] = [];

function isSameTree(p: TreeNode | null, q: TreeNode | null): boolean {
    ap = [];
    aq = [];
    
    dfs(p, ap);
    dfs(q, aq);
    
    if(ap.length !== aq.length) return false;
    for(let i=0; i<ap.length; i++) {
        if(ap[i] !== aq[i]) return false;
    }
    return true;
};

const dfs = (r: TreeNode, arr: Number[]): void => {
    if(!r) {
        arr.push(null)
        return;
    }
    arr.push(r.val);
    dfs(r.left, arr);
    dfs(r.right, arr);
}
