class Solution {
public:
    int secondHighest(string s) {
        int digits[10]={0};
        for(char c:s){
            if(c>='0' && c<='9') digits[c-'0']++;
        }
        bool flag = false;
        for(int i=9;i>=0;i--){
            if(digits[i]>0 && flag) return i;
            if(digits[i]>0) flag = true;
        }
        return -1;
    }
};