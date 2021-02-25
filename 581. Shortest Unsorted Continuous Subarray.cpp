class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
      vector<int> sortedNums = nums;
      sort(nums.begin(),nums.end());
      int minIdx=INT_MAX,lastIndex=0;
      for(int i=0;i<nums.size();i++){
        if(nums[i]!=sortedNums[i]){
          minIdx=min(minIdx,i);
          lastIndex=i;
        }
      }
      if(minIdx==INT_MAX) return 0;
      return lastIndex-minIdx+1;
    }
};
