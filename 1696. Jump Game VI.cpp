class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        multiset<int> pq;
        vector<int> dp(n,0);
        for(int i=0;i<n;i++){
            dp[i] = nums[i];
            if(!pq.empty())  dp[i] += *pq.rbegin();
            if(i-k>=0) pq.erase(pq.find(dp[i-k]));
            pq.insert(dp[i]);
        }
        return dp[n-1];
    }
};