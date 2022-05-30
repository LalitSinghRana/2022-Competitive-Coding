/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int cnt=0, ans=0, t=0;

void dfs(TreeNode* A) {
    if(A == NULL) return;
    dfs(A->left);
    cnt++;
    if(cnt == t) ans = A->val;
    dfs(A->right);
}

int Solution::kthsmallest(TreeNode* A, int B) {
    cnt=0;
    ans=0;
    t=B;
    dfs(A);
    return ans;
}
