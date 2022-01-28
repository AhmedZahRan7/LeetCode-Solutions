class Solution {
public:
    vector<int> sums;
    void trav(TreeNode* root,int acc){
        if(!root)return;
        if(!root->left && !root->right) sums.push_back(acc+root->val);
        else{
            trav(root->left,acc+root->val);
            trav(root->right,acc+root->val);
        }
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root) return false;
        trav(root,0);
        for(int s:sums) if(targetSum==s) return true;
        return false;
    }
};