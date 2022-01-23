class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> all;
        all.push_back(0);
        for(int i=1;i<10;i++) all.push_back(i);
        for(int i=2;i<10;i++){
            int add=i;
            int count = 10-i;
            int s = all.size();
            for(int j=s-count;j<s;j++) {
                all.push_back(all[j-1]*10+add);
                add++;
            }
        }
        vector<int> ans;
        for(int i:all) if(i>=low && i<=high)ans.push_back(i);
        return ans;
    }
};