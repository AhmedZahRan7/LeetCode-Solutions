class Solution {
public:
    
    vector<int> dp = vector<int>(1001,-1);
    int combinationSum4(vector<int>& nums, int target) {
        if(target==0) return 1;
        if(dp[target]!=-1) return dp[target];
        long long ans=0;
        for(int i:nums) if(i<=target) ans+=combinationSum4(nums,target-i);
        return dp[target] = ans;
    }
};