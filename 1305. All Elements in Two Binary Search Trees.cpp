class Solution {
public:
    void fill(TreeNode* r,vector<int>& arr){
        if(!r) return;
        fill(r->left,arr);
        arr.push_back(r->val);
        fill(r->right,arr);
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> arr1,arr2,ans;
        fill(root1,arr1);
        fill(root2,arr2);
        int a=0,b=0;
        while(a<arr1.size() || b<arr2.size()){
            if(a == arr1.size()) ans.push_back(arr2[b++]);
            else if (b == arr2.size()) ans.push_back(arr1[a++]);
            else{
                if(arr1[a]<arr2[b]) ans.push_back(arr1[a++]);
                else ans.push_back(arr2[b++]);
            }
        }
        return ans;
    }
};