class Solution {
public:
    int removePalindromeSub(string s) {
        int n=s.size();
        if(n==0) return 0;
        bool isPal=true;
        for(int i=0;i<=n/2;i++) if(s[i]!=s[n-i-1]) isPal=false;
        if(isPal) return 1;
        else return 2;
    }
};