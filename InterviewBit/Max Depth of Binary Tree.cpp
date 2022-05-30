/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int ans=0;

void dfs(TreeNode* A, int d) {
    if(!A) return;
    d++;
    if(d > ans) ans = d;
    dfs(A->left, d);
    dfs(A->right, d);
}

int Solution::maxDepth(TreeNode* A) {
    ans=0;
    if(A==NULL) return 0;
    dfs(A,0);
    return ans;
}
