class Solution {
    private List<Integer> ans = new ArrayList<Integer>();
    private int solve(TreeNode root,int[] voyage,int idx){
        if(idx==voyage.length) return 0;
        if(root==null) return idx;
        if(root.val != voyage[idx]){
            return -1;
        }
        if(root.right == null && root.left == null) return idx+1;
        if(root.left != null && root.right != null && root.right.val == voyage[idx+1]){
            TreeNode temp = root.right;
            root.right = root.left;
            root.left = temp;
            ans.add(root.val);
        }
        else if(root.left != null && root.left.val != voyage[idx+1]){
            return -1;
        }
        int rightIdx = solve(root.left,voyage,idx+1);
        if(rightIdx==-1) return -1;
        return solve(root.right, voyage, rightIdx);
    }

    public List<Integer> flipMatchVoyage(TreeNode root, int[] voyage) {
        if(solve(root, voyage, 0)==-1) return new ArrayList<>(Arrays.asList(-1));
        return ans;
    }
}