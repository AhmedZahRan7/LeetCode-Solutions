class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        string sub = sentence1.size()>sentence2.size() ? sentence2 : sentence1;
        string ful = sentence1.size()>sentence2.size() ? sentence1 : sentence2;

        vector<int> spaces;
        for(int i=0;i<sub.size();i++) if(sub[i]==' ') spaces.push_back(i);
        
        if(ful.substr(0,sub.size()) == sub && (sub.size()>=ful.size() || ful[sub.size()]==' ')) return true;
        if(ful.substr(ful.size()-sub.size()) == sub && (ful.size() - sub.size() - 1 < 0 || ful[ful.size() - sub.size() -1 ]==' ') ) return true;

        for(int sp:spaces){
            if(ful.substr(0,sp) == sub.substr(0,sp) && sub.substr(sp+1) == ful.substr(ful.size() -sub.substr(sp+1).size())) return true;
        }
        return false;
    }
};