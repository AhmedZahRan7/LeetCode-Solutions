class Solution {
public:
    int n,m;
    bool valid(int i,int j){
        return i>=0 && j>=0 && i < n && j < m;
    }
    int xOffset[4] = {0,0,1,-1};
    int yOffset[4] = {1,-1,0,0};
    
    int spread(vector<vector<int>>& grid,int i,int j,vector<vector<bool>>& visited){
        if(!valid (i,j) || visited[i][j] || !grid[i][j]) return 0;
        int ans=1;
        visited[i][j] = true;
        for(int off=0;off<4;off++) ans += spread(grid,i+xOffset[off],j+yOffset[off],visited);
        return ans;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        vector<vector<bool>> visited (n,vector<bool>(m,false));
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans = max(ans,spread(grid,i,j,visited));
            }
        }
        return ans;
    }
};