class Solution {
    private TreeNode solve(TreeNode root, int v, int d, Boolean fromRight){
        if(d==1 && root==null) return new TreeNode(v);
        if(root==null) return null;
        if(d==1 && !fromRight){
            TreeNode newRoot = new TreeNode(v);
            newRoot.left=root;
            return newRoot;
        }
        if(d==1 && fromRight){
            TreeNode newRoot = new TreeNode(v);
            newRoot.right=root;
            return newRoot;
        }
        root.right = solve(root.right, v, d-1, true);
        root.left = solve(root.left, v, d-1, false);
        return root;
    }
    public TreeNode addOneRow(TreeNode root, int v, int d) {
        return solve(root, v, d, false);
    }
}