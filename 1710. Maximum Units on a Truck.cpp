class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(),boxTypes.end(),[](vector<int>&a,vector<int>&b){
            return a[1] >= b[1];
        });
        int sum=0;
        for(int i=0;i<boxTypes.size();i++){
            int units = min(truckSize,boxTypes[i][0]);
            sum += units*boxTypes[i][1];
            truckSize -= units;
            if(truckSize == 0) break;
        }
        return sum;
    }
};