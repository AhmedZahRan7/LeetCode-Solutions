class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<char> charStack;
        stack<int> freqStack;

        for(char c:s){
            if(charStack.empty()) {
                charStack.push(c);
                freqStack.push(1);
            }
            else{
                if(c==charStack.top() && freqStack.top()==k-1) for(int i=0;i<k-1;i++){
                    charStack.pop();
                    freqStack.pop();
                }
                else if (c==charStack.top()){
                    charStack.push(c);
                    freqStack.push(freqStack.top()+1);
                }
                else {
                    charStack.push(c);
                    freqStack.push(1);
                }
            }
        }
        string ans = "";
        while(!charStack.empty()) {
            ans = charStack.top()+ans;
            charStack.pop();
        }
        return ans;
    }
};