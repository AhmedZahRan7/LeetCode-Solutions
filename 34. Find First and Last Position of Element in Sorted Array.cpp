class Solution {
public:
    vector<int> nums;
    int target;
    int firstOCC(int l,int r){
        if(l>r) return -1;
        int mid = l + (r-l)/2;
        if(nums[mid]==target &&(mid==0||nums[mid-1]!=target)) return mid;
        if(nums[mid]>=target) return firstOCC(l,mid-1);
        return firstOCC(mid+1,r);
    }
    int lastOCC(int l,int r){
        if(l>r) return -1;
        int mid = l + (r-l)/2;
        if(nums[mid]==target &&(mid==nums.size()-1||nums[mid+1]!=target)) return mid;
        if(nums[mid]>target) return lastOCC(l,mid-1);
        return lastOCC(mid+1,r);
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        this->nums=nums;
        this->target=target;
        return {firstOCC(0,nums.size()-1),lastOCC(0,nums.size()-1)};
    }
};