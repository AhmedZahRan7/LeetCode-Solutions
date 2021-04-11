class Solution {
public:
    int deepestLeavesSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int size = 1;
        int accumelator = 0;
        while(!q.empty()){
            TreeNode* current = q.front();
            q.pop();
            if(current->left != NULL) q.push(current->left);
            if(current->right != NULL) q.push(current->right);
            accumelator+=current->val;
            size--;
            if(size==0){
                size = q.size();
                if(!q.empty()) accumelator=0;
            }
        }
        return accumelator;
    }
};