// Binary Search Solution
// class Solution {
// public:
//     bool binarySearch(vector<int>& v, int target,int from,int to){
//         if(from>to) return false;
//         int mid = from + (to-from)/2;
//         if(v[mid]==target) return true;
//         if(v[mid]> target) return binarySearch(v,target,from,mid-1);
//         return binarySearch(v,target,mid+1,to);
//     }
//     bool searchMatrix(vector<vector<int>>& matrix, int target) {
//         int n=matrix.size();
//         int m=matrix[0].size();
//         for(vector<int>& v:matrix){
//             if(v[0]<=target && v[m-1]>=target && binarySearch(v,target,0,m-1)) return true;
//         }
//         return false;
//     }
// };

// Iterative Solution
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int i = matrix.size()-1;
        int j=0;
        
        while(i>=0 && j<matrix[0].size()){
            if(matrix[i][j]>target) i--;
            else if (matrix[i][j]<target) j++;
            else return true;
        }
        return false;
    }
};