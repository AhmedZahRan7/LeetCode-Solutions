class Solution {
public:
    int countBinarySubstrings(string s) {
        int lastCons = 0;
        int currCons = 1;
        int ans = 0;
        for(int i=1;i<s.size();i++){
            if(s[i]==s[i-1]) currCons++;
            else{
                ans+=min(lastCons,currCons);
                lastCons = currCons;
                currCons = 1;
            }
        }
        return ans+min(lastCons,currCons);
    }
};