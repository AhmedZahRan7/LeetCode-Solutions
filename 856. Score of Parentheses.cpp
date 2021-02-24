class Solution {
public:
    int scoreOfParentheses(string S) {
        int stackPointer=0;
        int accumelator=0;
        for(int i=0;i<S.size();i++){
          if(S[i]=='(') stackPointer++;
          else if(S[i]==')' && S[i-1]=='(') {
            stackPointer--;
            accumelator+=(1<<stackPointer);
          }
          else stackPointer--;
        }
        return accumelator; 
    }
};

