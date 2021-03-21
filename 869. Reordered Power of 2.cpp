class Solution {
public:  
    bool eqVec(vector<int>& v1,vector<int>& v2){
        for(int i=0;i<v1.size();i++){
            if(v1[i]!=v2[i]) return false;
        }
        return true;
    }
    bool reorderedPowerOf2(int N) {
        vector<int> freq(10,0);
        while(N>0){
            freq[N%10]++;
            N/=10;
        }
        long long pow = 1;
        while(pow<INT_MAX){
            long long temp = pow;
            vector<int> freqTemp(10,0);
            while(temp>0){
                freqTemp[temp%10]++;
                temp/=10;
            }
            if(eqVec(freq,freqTemp)) return true;
            pow = pow<<1;
        }
        return false;
    }
};