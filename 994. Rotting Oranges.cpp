class Solution {
public:

    vector<int> xdir{0,0,1,-1};
    vector<int> ydir{1,-1,0,0};
    int n,m;
    bool valid(int i,int j){
        return i>=0 && j>=0 && i<n && j<m;
    }
    
    int orangesRotting(vector<vector<int>>& grid) {

        queue<pair<int,int>> q;
        n = grid.size();
        m = grid[0].size();
        
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++) if(grid[i][j] == 2) q.push({i,j});
        
        int level = 0;
        int count = q.size();
        bool added = false;
        while(!q.empty()){
            pair<int,int> rot = q.front();
            q.pop();
            for(int d=0;d<4;d++){
                if(valid(rot.first+xdir[d],rot.second+ydir[d]) && grid[rot.first+xdir[d]][rot.second+ydir[d]] == 1 ){
                    grid[rot.first+xdir[d]][rot.second+ydir[d]] = 2;
                    q.push({rot.first+xdir[d],rot.second+ydir[d]});
                    added = true;
                }
            }
            count --;
            if(count == 0) {
                count = q.size();
                if(added) level++;
                added = false;
            }
        }
        
        
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++) if(grid[i][j] == 1) return -1;
        
        return level;
    }
};
