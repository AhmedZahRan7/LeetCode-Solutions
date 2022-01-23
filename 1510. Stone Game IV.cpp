class Solution {
public:
    int dp[100001][2];
    
    int solve(int rem,bool turn){
        if(rem==0) return false;
        if(dp[rem][turn] != -1) return dp[rem][turn];
        for(int i=1;i*i<=rem;i++){
            if(solve(rem-i*i,!turn)==0) return dp[rem][turn]=1;
        }
        return dp[rem][turn]=0;
    }
    bool winnerSquareGame(int n) {
        memset(dp,-1,sizeof(dp));
        return solve(n,0);
    }
};