class Solution {
public:
    vector<int> xdir{0,0,1,-1};
    vector<int> ydir{1,-1,0,0};
    int n,m;
    
    bool valid(int i,int j){
        return i>=0 && j>=0 && i<n && j<m;
    }
    
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        n =mat.size();
        m =mat[0].size();
        vector<vector<int>> ans (n,vector<int>(m,INT_MAX));
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++) if(mat[i][j] == 0) {
                q.push({i,j});
                ans[i][j] = 0;
            }
        }
        
        while(!q.empty()){
            pair<int,int> c = q.front();
            q.pop();
            for(int i=0;i<4;i++){
                int newx = c.first + xdir[i];
                int newy = c.second + ydir[i];
                if(valid(newx,newy)){
                    if(ans[newx][newy] == INT_MAX) q.push({newx,newy});
                    ans[newx][newy] = min(ans[newx][newy],ans[c.first][c.second]+1);
                }
            }
        }
        return ans;
    }
};