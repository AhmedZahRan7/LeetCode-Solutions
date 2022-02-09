class Solution {
public:
    vector<int> intersection(vector<int>v1,vector<int>v2){
        if(v1[0]>=v2[0] && v1[0]<=v2[1]) return {v1[0],min(v1[1],v2[1])};
        if(v2[0]>=v1[0] && v2[0]<=v1[1]) return {v2[0],min(v2[1],v1[1])};
        return {};
    }
    
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> ans;
        int i=0,j=0;
        while(i<firstList.size() && j<secondList.size()){
            vector<int> inter = intersection(firstList[i],secondList[j]);
            if(inter.size()==0){
                if(secondList[j][0]<firstList[i][1]) j++;
                else i++;
            }
            else{
                ans.push_back(inter);
                if(secondList[j][1]<firstList[i][1]) j++;
                else i++;
            }
        }
        return ans;
    }
};