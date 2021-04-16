class Solution {
public:
    bool cmp(string& s1, string& s2,map<char,int>& m){
        int n = s1.size();
        for(int i=0;i<n;i++){
            if(i==s2.size() || m[s1[i]]>m[s2[i]]) return false;
            if(m[s1[i]]!=m[s2[i]]) break;
        }
        return true;
    }
    bool isAlienSorted(vector<string>& words, string order) {
        map<char,int> m;
        for(int i =0;i<order.size();i++) m[order[i]]=i;
        for(int i=0;i<words.size()-1;i++){
            if(!cmp(words[i],words[i+1],m)) return false;
        }
        return true;
    }
};