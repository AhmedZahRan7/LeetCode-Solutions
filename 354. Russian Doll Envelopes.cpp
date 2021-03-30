class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(),envelopes.end());
        int n = envelopes.size();
        vector<int> arr(n,1);
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(envelopes[i][0]<envelopes[j][0] &&
                   envelopes[i][1]<envelopes[j][1]) arr[j] = max(arr[j],arr[i]+1);
            }
        }
        int ans=0;
        for(int i:arr) ans = max(ans,i);
        return ans;
    }
};