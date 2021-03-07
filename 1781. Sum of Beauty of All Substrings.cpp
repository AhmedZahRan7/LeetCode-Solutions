class Solution {
public:
    int beauty(vector<int>& arr){
        int mx=-1;
        int mn=10000;
        for(int i:arr){
            if(i!=0) {
                mx=max(mx,i);
                mn=min(mn,i);
            }
        }
        return mx-mn;
    }
    int beautySum(string s) {
        int n = s.size();
        vector<int> freq(26,0);
        int accumelator = 0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                freq[s[j]-'a']++;
                accumelator += beauty(freq);
            }
            for(int j=0;j<26;j++) freq[j]=0;
        }
        return accumelator;

    }
};
