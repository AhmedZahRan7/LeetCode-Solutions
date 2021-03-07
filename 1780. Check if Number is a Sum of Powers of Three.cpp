class Solution {
public:
    int getX(int n){
        int i=1;
        while(i*3<=n) i*=3;
        return i;
    }
    bool checkPowersOfThree(int n) {
        if(n==0) return true;
        int x = getX(n);
        if(n-x >= x) return false;
        return checkPowersOfThree(n-x);
    }
};