class Solution {
public:
    bool isSubString(string entry,string s){
        if(entry.size()>s.size()) return false;
        int i=0;
        for(char c:entry){
            if(i>=s.size()) return false;
            while(s[i] != c && i<s.size()) i++;
            i++;
        }
        return i<=s.size();
    }
    string findLongestWord(string s, vector<string>& d) {
        sort(d.begin(),d.end());
        string ans="";
        for(string entry:d){
            if(entry.size()>ans.size() && isSubString(entry,s)) ans = entry;
        }
        return ans;
    }
};