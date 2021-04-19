class Solution {
public:
    bool inside(vector<int>& q, vector<int>& p){
        int x1 = q[0], x2 = p[0], y1=q[1], y2 = p[1], r=q[2];
        double d = (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
        return sqrt(d)<=r;
    }
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        vector<int> ans;
        for(vector<int>& q : queries){
            int pointsIN = 0;
            for(vector<int>& p : points) pointsIN += inside(q,p);
            ans.push_back(pointsIN);
        }
        return ans;
    }
};