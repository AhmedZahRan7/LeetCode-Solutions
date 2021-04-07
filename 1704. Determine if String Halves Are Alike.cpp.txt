class Solution {
public:
    bool halvesAreAlike(string s) {
        int v=0;
        int n=s.size();
        string vowels = "aeiouAEIOU";
        for(int i=0;i<n/2;i++){
            bool ex = false;
            for(char c:vowels) if(c==s[i]) ex=true;
            if(ex) v++;
        }
        for(int i=n/2;i<n;i++){
            bool ex = false;
            for(char c:vowels) if(c==s[i]) ex=true;
            if(ex) v--;
        }
        return v==0;
    }
};