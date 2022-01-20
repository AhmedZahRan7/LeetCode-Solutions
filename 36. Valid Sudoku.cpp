class Solution {
public:
    int getSquare(int i,int j){
        return 3*(i/3) + (j/3);
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<bool>> columns(9,vector<bool>(9,false));
        vector<vector<bool>> rows(9,vector<bool>(9,false));
        vector<vector<bool>> squares(9,vector<bool>(9,false));
        
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                char c = board[i][j];
                if(c == '.') continue;
                if(columns[i][c-'1'] || rows[j][c-'1'] || squares[getSquare(i,j)][c-'1']) return false;
                
                squares[getSquare(i,j)][c-'1'] = true;
                columns[i][c-'1'] = true;
                rows[j][c-'1'] = true;
            }
        }
        return true;
    }
};