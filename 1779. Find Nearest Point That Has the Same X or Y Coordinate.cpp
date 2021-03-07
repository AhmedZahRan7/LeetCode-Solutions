class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        int minManhattan = INT_MAX;
        int minIdx = -1;
        for(int i=0;i<points.size();i++){
            if(points[i][0]==x && abs(points[i][1]-y) < minManhattan) {
                minManhattan = abs(points[i][1]-y);
                minIdx=i;
            }
            if(points[i][1]==y && abs(points[i][0]-x) < minManhattan) {
                minManhattan = abs(points[i][0]-x);
                minIdx=i;
            }
        }
        return minIdx;
    }
};
