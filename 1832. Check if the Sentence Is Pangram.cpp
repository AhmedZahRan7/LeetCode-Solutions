class Solution {
public:
    bool checkIfPangram(string sentence) {
        int m[26]={0};
        for(char c:sentence) m[c-'a']++;
        for(int i=0;i<26;i++) if(m[i]==0) return false;
        return true;
    }
};