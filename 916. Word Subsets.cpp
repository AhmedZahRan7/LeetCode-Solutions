
class Solution {
public:
    bool cmp(int word[],int sub[]){
        for(int i=0;i<26;i++) if(sub[i]>word[i]) return false;
        return true;
    }
    vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
        vector<string> ans;
        int mustHave[26]={0};
        for(string &sub : B){
            int subFreq [26] = {0};
            for(char c:sub) subFreq[c-'a']++;
            for(int i=0;i<26;i++) mustHave[i] = max(mustHave[i],subFreq[i]); 
        }
        for(string &word : A){
            int freq [26] = {0};
            for(char c:word) freq[c-'a']++;
            if(cmp(freq,mustHave)) ans.push_back(word);
        }
        return ans;
    }
};