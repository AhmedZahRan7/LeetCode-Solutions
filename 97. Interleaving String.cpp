class Solution {
public:
    string str1, str2, str3;
    int mem[101][101];
    bool solve(int i=0,int j=0){
        if(i==str1.size() && j==str2.size()) return true;
        if(mem[i][j]!=-1) return mem[i][j];
        bool ans1=false,ans2=false;
        if(i<str1.size() && str1[i] == str3[i+j]) ans1=solve(i+1,j);
        if(j<str2.size() && str2[j] == str3[i+j]) ans2=solve(i,j+1);
        return mem[i][j] = ans1 || ans2;
    }
    bool isInterleave(string s1, string s2, string s3) {
        memset(mem,-1,sizeof(mem));
        str1 = s1;
        str2 = s2;
        str3 = s3;
        int n = s1.size(), m = s2.size(), r = s3.size(); 
        if(r!= n+m) return false;
        if(r == 0) return true;
        return solve();
    }
}; 