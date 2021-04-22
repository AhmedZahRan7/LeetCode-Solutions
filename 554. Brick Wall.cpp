class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<int,int> m;
        int maxFreq = 0;
        for(vector<int>& row : wall){
            int prefixSum = 0;
            for(int i=0;i<row.size()-1;i++) {
                prefixSum += row[i];
                m[prefixSum]++;
                maxFreq = max(maxFreq,m[prefixSum]);
            }
        }
        return wall.size()-maxFreq;
    }
};