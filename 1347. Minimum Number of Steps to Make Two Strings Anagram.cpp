class Solution {
public:
    int minSteps(string s, string t) {
        int smap[26]={0};
        int tmap[26]={0};
        for(char c:s)smap[c-'a']++;
        for(char c:t)tmap[c-'a']++;
        int mutual = 0;
        for(int i=0;i<26;i++) mutual += min(smap[i],tmap[i]);
        return s.size()-mutual;
    }
};