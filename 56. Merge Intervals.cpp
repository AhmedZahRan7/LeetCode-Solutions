class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> ans;
        for(vector<int>& v:intervals){
            if(ans.empty()) ans.push_back(v);
            else{
                if(v[0]<=ans.back()[1]) ans.back()[1] = max(ans.back()[1],v[1]);
                else ans.push_back(v);
            }
        }
        return ans;
    }
};