class Solution {
public:
    string intToRoman(int num) {
        string ans="";
        map<int,string> m {
            {1,"I"},{5,"V"},{10,"X"},{50,"L"},{100,"C"},{500,"D"},{1000,"M"},
            {4,"IV"},{9,"IX"},{40,"XL"},{90,"XC"},{400,"CD"},{900,"CM"},
        };
        while(num>0){
            map<int, string>::reverse_iterator it;
            for (it = m.rbegin(); it != m.rend(); it++) {
                int val = it->first;
                string s = it->second;
                if(num>=val){
                    ans+=s;
                    num-=val;
                    break;
                }
            } 
        }
        return ans;
    }
};