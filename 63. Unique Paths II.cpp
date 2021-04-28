class Solution {
public:
    vector<vector<int>> obstacleGrid;
    int mem[101][101];
    int numOfWays(int i=0,int j=0){
        if(mem[i][j]!=-1) return mem[i][j];
        if(i>=obstacleGrid.size() || j>=obstacleGrid[0].size() || obstacleGrid[i][j]) return 0;
        if(i==obstacleGrid.size()-1 && j==obstacleGrid[0].size()-1) return 1;
        return mem[i][j] = numOfWays(i+1,j)+numOfWays(i,j+1);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        memset(mem,-1,sizeof(mem));
        this->obstacleGrid = obstacleGrid;
        return numOfWays();
    }
};