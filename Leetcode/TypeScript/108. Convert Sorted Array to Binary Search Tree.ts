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

function sortedArrayToBST(nums: number[]): TreeNode | null {
    if(!nums.length) return null;
    
    let mid: number = Math.floor(nums.length/2);
    let left: number[] = nums.slice(0,mid);
    let right: number[] = nums.slice(mid+1, nums.length);
    
    return new TreeNode(nums[mid], sortedArrayToBST(left), sortedArrayToBST(right))
};
