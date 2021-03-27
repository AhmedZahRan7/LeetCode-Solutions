class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        vector<vector<bool>> dp (n,vector<bool>(n,false));
        int count = 0;
        for(int i=n-1;i>=0;i--){
            for(int j=n-1;j>=i;j--){
                if(i==j){
                    dp[i][j] = true;
                    count++;
                    continue;
                }
                if (s[i]==s[j] && (j-1<i+1 || dp[i+1][j-1])){
                    dp[i][j] = true;
                    count++;
                    continue;
                }
            }
        }
        return count;
    }
};