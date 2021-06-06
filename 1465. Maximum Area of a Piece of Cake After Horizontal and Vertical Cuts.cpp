class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        horizontalCuts.push_back(0);
        horizontalCuts.push_back(h);
        verticalCuts.push_back(0);
        verticalCuts.push_back(w);
        sort(horizontalCuts.begin(),horizontalCuts.end());
        sort(verticalCuts.begin(),verticalCuts.end());
        int max_hori = 0,max_vert = 0;
        
        for(int i=1;i<horizontalCuts.size();i++)
            max_hori = max(max_hori,horizontalCuts[i]-horizontalCuts[i-1]);
        
        for(int i=1;i<verticalCuts.size();i++)
            max_vert = max(max_vert,verticalCuts[i]-verticalCuts[i-1]);
        
        long ans = 1L * max_hori * max_vert;
        return (int) (ans % 1000000007);
    }
};