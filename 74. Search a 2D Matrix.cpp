class Solution {
public:
    
    int getLower(vector<vector<int>>& matrix,int target,int l,int r){
        if(l>=r) return r;
        int m = l + (r-l+1)/2;
        if(matrix[m][0] > target) return getLower(matrix,target,l,m-1);
        return getLower(matrix,target,m,r);
    }
    
    bool bs(vector<int>& row,int target,int l,int r){
        if(l>r) return false;
        int m = l + (r-l)/2; 
        if(row[m] ==target) return true;
        if(row[m] > target) return bs(row,target,l,m-1);
        return bs(row,target,m+1,r);
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size(),m=matrix[0].size();
        int row = getLower(matrix,target,0,n-1);
        return bs(matrix[row],target,0,m-1);
    }
};