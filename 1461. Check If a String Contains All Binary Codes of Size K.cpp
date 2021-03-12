class Solution {
public:
    // 110011 
    // k=3
    // num = [110] first 3 digits
    // num = 1*2^2 + 1*2^1 + 0*2^0
    // each step we move one digit
    // [110] -> [100] remove left one add zero to right 
    bool hasAllCodes(string s, int k) {
        int n = s.size();
        if(k>n) return false;
        vector<bool> exist(1<<k,false);
        int num = 0;

        for(int i=0;i<k;i++) num+= (s[i]-'0') * (1<<(k-i-1));
        exist[num]=true;
        for(int i=k;i<n;i++){
            num -= (s[i-k]-'0') * (1<<(k-1));
            num = num<<1;
            num += (s[i]-'0');
            exist[num]=true;
        }

        for(bool b:exist) if(!b) return false;
        return true;
    }
};