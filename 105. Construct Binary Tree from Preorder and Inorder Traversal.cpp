class Solution {
public:
    unordered_map<int,int> indexInOrder;
    vector<int> in,pre;
    TreeNode* build(int preIdx, int from,int to){
        if(from>to) return NULL;
        int inIdx = indexInOrder[pre[preIdx]];
        return new TreeNode(pre[preIdx],
                            build(preIdx+1,from,inIdx-1),
                            build(preIdx+inIdx-from+1,inIdx+1,to));
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        in = inorder;
        pre = preorder;
        for(int i=0;i<inorder.size();i++) indexInOrder[inorder[i]] = i;
        return build(0,0,inorder.size()-1);
    }
};