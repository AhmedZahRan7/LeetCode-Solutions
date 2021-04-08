class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits == "") return {};
        vector<string> letters = {"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string> ans = {""};
        for(char &c:digits){
            vector<string> temp;
            for(char &l:letters[c-'2']){
                for(string& s:ans) temp.push_back(s+l);
            }
            ans = temp;
        }
        return ans;
    }
};