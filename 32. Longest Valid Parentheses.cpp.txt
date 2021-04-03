class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        stack<int> stack;
        vector<int> couples(n,-1);
        for (int i=0;i<n;i++){
            if(s[i]=='(') stack.push(i);
            else{
                if(stack.empty()) continue;
                int myCouple = stack.top();
                stack.pop();
                couples[myCouple] = i;
                couples[i] = myCouple;
            }
        }
        int ans=0;
        int seq=0;
        for(int i:couples){
            if(i!=-1) seq++;
            else seq=0;
            ans= max(ans,seq);
        }
        return ans;
    }
};