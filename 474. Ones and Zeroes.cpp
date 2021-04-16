class Solution {
public:
    int dp [101][101][601];
    int solve(vector<string>& strs, int m, int n,int i=0){
        if(i==strs.size()) return 0;
        if(dp[m][n][i]!=-1) return dp[m][n][i]; 
        int z=0,o=0;
        for(char c:strs[i]){
            if(c=='0') z++;
            else o++;
        }
        if(z>m || o>n) return dp[m][n][i]=solve(strs,m,n,i+1);
        return dp[m][n][i] = max (
            1+solve(strs,m-z,n-o,i+1),
            solve(strs,m,n,i+1)
        );
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        memset(dp,-1,sizeof(dp));
        return solve(strs,m,n);
    }
};