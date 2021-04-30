class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        unordered_set<int> s;
        int t = 1;
        int l = 1;
        while(true){
            bool exist = false;
            while(true){
                if(l+t>bound) break;
                s.insert(l+t);
                exist = true;
                if(y==1) break;
                t *= y;
            }
            if(!exist || x==1) break;
            l *= x;
            t = 1;
        }
        return vector<int>(s.begin(), s.end());
    }
};