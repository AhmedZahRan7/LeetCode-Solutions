class Solution {
public:
    int dp[201][201];
    vector<int> xOffset = {0,0,1,-1};
    vector<int> yOffset = {1,-1,0,0};
    bool valid(vector<vector<int>>& matrix,int i,int j){
        return (i>=0 && j>=0 && i<matrix.size() && j<matrix[0].size());
    }

    int solve(vector<vector<int>>& matrix,int i,int j){
        if(dp[i][j]!=-1) return dp[i][j];
        int ans = 1;
        for(int of=0;of<4;of++){
            int newI = i+xOffset[of];
            int newJ = j+yOffset[of];
            if(valid(matrix,newI,newJ) && matrix[newI][newJ]>matrix[i][j]){
                ans = max(ans,1+solve(matrix,newI,newJ));
            }
        }
        return dp[i][j] = ans;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        memset(dp,-1,sizeof(dp));
        int ans=0;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++) ans = max(ans,solve(matrix,i,j));
        }
        return ans;
    }
};
