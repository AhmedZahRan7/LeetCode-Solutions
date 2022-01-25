class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int n = arr.size();
        if(n<3) return false;
        int l=1,r=n-2;
        while(l<n && arr[l]>arr[l-1]) l++;
        while(r>=0 && arr[r]>arr[r+1]) r--;
        if(l==n || r==-1 || l-r!=2) return false;
        return true;
    }
};