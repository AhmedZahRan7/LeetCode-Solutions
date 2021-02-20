class Solution {
public:
    int romanToInt(string s) {
        map<string,int> m;
        m["I"]=1;
        m["V"]=5;
        m["X"]=10;
        m["L"]=50;
        m["C"]=100;
        m["D"]=500;
        m["M"]=1000;
        m["IV"]=4;
        m["IX"]=9;
        m["XL"]=40;
        m["XC"]=90;
        m["CD"]=400;
        m["CM"]=900;
        
        int ans=0;
        for(int i=0;i<s.size();i++){
            string temp;
            temp.push_back(s[i]);
            if( i+1< s.size() ){
                temp.push_back(s[i+1]);
                if(m.find(temp) != m.end()) {
                    ans+=m[temp];
                    i++;
                    continue;
                }
                else temp.pop_back();
            }
            ans+=m[temp];
        }
        return ans;
    }
};