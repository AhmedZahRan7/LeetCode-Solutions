class Solution {
public:
    long long dp[1001];
    int numFactoredBinaryTrees(vector<int>& arr) {
        memset(dp,0,sizeof(dp));
        int n=arr.size();
        sort(arr.begin(),arr.end());
        unordered_map<int,int> m;
        for(int i=0;i<n;i++) m[arr[i]]=i;
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<=i;j++){
                if(j==i) dp[i]++;
                else if(arr[i]%arr[j]!=0) continue;
                else if (m.find(arr[i]/arr[j])!=m.end()) dp[i]+=dp[j]*dp[m[arr[i]/arr[j]]];
                dp[i]%=1000000007;
            }
        }
        for(int i=0;i<n;i++){
            ans+=dp[i];
            ans%=1000000007;
        }
        return ans;
    }
};