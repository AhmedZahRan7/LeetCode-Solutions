class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int max = 1;
        while(maximumBit--) max = max<<1;
        max--;
        int xo = nums[0];
        for(int i=1;i<nums.size();i++) xo = xo ^ nums[i];
        vector<int> ans;
        ans.push_back(max^xo);
        for(int i=nums.size()-1;i>0;i--){
            xo = xo ^ nums[i];
            ans.push_back(max^xo);
        }
        return ans;
    }
};