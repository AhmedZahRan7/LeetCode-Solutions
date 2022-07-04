class Solution {
public:
    int candy(vector<int>& ratings) {
        int n =ratings.size();
        vector<int> candis(n,1);
        for(int i=1;i<n;i++){
            if(ratings[i]>ratings[i-1]) candis[i] = candis[i-1]+1;
        }
        for(int i=n-2;i>=0;i--){
            if(ratings[i]>ratings[i+1]) candis[i] = max(candis[i],candis[i+1]+1);
        }
        int ans=0;
        ans = accumulate(candis.begin(),candis.end(),0);
        return ans;
    }
};