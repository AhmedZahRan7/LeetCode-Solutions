class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n=nums.size();
        vector<int> freq(n+1);
        for(int i:nums) freq[i]++;
        int zeroRep,twoRep;
        for(int i=1;i<=n;i++){
            if(freq[i]==0) zeroRep=i;
            if(freq[i]==2) twoRep=i;
        }
        return {twoRep,zeroRep};
    }
};