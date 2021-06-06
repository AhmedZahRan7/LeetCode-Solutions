class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,bool> m;
        for(int i:nums) m[i] = true;
        int ans=0;
        for(int i:nums){
            if(!m[i-1]){
                int j = i+1;
                int temp = 1;
                while(m[j]) temp++,j++;
                ans = max(ans,temp);
            }
        }
        return ans;
    }
};