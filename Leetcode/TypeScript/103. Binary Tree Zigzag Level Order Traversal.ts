function zigzagLevelOrder(root: TreeNode | null): number[][] {
    let q = [], ans = [], flag = false;
    if(root) q.push(root);
    
    while(q.length) {
        let size = q.length;
        let v = [];
        
        while(size--) {
            let x = q.shift();
            v.push(x.val);
            if(x.left) q.push(x.left);
            if(x.right) q.push(x.right);
        }
        
        if(flag) v.reverse();
        ans.push(v);
        flag = !flag;
    }
    
    return ans;
};
