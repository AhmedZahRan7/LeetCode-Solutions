class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int ans = 0;
        unordered_map<int,int> m;
        int l=0,r=0;
        int temp=0;
        vector<int> prefixSum;
        prefixSum.push_back(nums[0]);
        for(int i=1;i<nums.size();i++) prefixSum.push_back(nums[i] + prefixSum[i-1]);
        while(r<nums.size()){
            if( !m.count(nums[r]) || m[nums[r]]<l){
                temp+=nums[r];
                m[nums[r]] = r;
                ans = max(ans,temp);
                r++;
            }
            else{
                temp -= prefixSum[m[nums[r]]];
                if(l>0) temp += prefixSum[l-1];
                l = m[nums[r]]+1;
            }
        }
        return ans;
    }
};