class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> stack;
        vector<bool> remove(s.size());
        for(int i=0;i<s.size();i++){
            if(s[i]=='(') stack.push(i);
            else if(s[i]==')'){
                if(!stack.empty())stack.pop();
                else remove[i]=true;
            }
        }
        while(!stack.empty()){
            remove[stack.top()]=true;
            stack.pop();
        }
        string newS;
        for(int i=0;i<s.size();i++) if(!remove[i]) newS.push_back(s[i]);
        return newS;
    }
};