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
let i: number[];
let j: number[];

function isSymmetric(root: TreeNode | null): boolean {
    i = [];
    j = [];

    dfsI(root.left);
    dfsJ(root.right);
    
    if(i.length !== j.length) return false;
    for(let k=0; k<i.length; k++) { 
        if(i[k] !== j[k]) return false;
    }
    return true;
};

const dfsI = (r: TreeNode | null) => {
    if(!r) {
        i.push(null);
        return;
    }
    i.push(r.val);
    dfsI(r.left);
    dfsI(r.right);
}

const dfsJ = (r: TreeNode | null) => {
    if(!r) {
        j.push(null);
        return;
    }
    j.push(r.val);
    dfsJ(r.right);
    dfsJ(r.left);
}
