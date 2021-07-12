class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> stot;
        unordered_map<char,char> ttos;
        for(int i=0;i<s.size();i++){
            char sc = s[i] , tc = t[i];
            if((stot.count(sc) == 0 || stot[sc] == tc) &&
               (ttos.count(tc) == 0 || ttos[tc] == sc))  stot[sc] = tc,ttos[tc] = sc;
            else return false;
        }
        return true;
    }
};
