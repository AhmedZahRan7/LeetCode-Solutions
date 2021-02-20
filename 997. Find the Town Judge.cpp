class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        vector<int> numOfPepoleITrust(N+1);
        vector<int> numOfPepoleTrustMe(N+1);
        for(vector<int> t : trust) {
            numOfPepoleITrust[t[0]]++;
            numOfPepoleTrustMe[t[1]]++;
        }
        for(int i=1;i<=N;i++){
            if(numOfPepoleITrust[i]==0 &&
               numOfPepoleTrustMe[i]==N-1) return i;
        }
        return -1;
    }
};