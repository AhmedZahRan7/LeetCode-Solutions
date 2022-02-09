class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        unordered_map<int,bool> visited;
        for(int i:nums) m[i]++;
        int ans = 0;
        for(int i:nums){
            if(visited[i]) continue;
            int target = i+k;
            if(target == i && m[i]>1) ans++;
            else if(target != i && m[target]>0) ans++;
            visited[i]=true;
        }
        return ans;
    }
};