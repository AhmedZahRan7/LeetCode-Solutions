class Solution {
public:
    int rev(int num){
        vector<int> v;
        while(num>0){
            v.push_back(num%10);
            num/=10;
        }
        int ans = 0;
        for(int i:v) {
            ans *= 10;
            ans += i;
        }
        return ans;
    }
    int countNicePairs(vector<int>& nums) {
        int n = nums.size();
        vector<int> diff(n);
        for(int i=0;i<n;i++) diff[i] = nums[i] - rev(nums[i]);
        unordered_map<int,int> m;
        for (int d:diff) m[d]++;
        long long ans=0;
        for(auto p:m){
            long long freq = p.second - 1;
            ans += (freq * (freq+1))/2;
            ans %= 1000000007;
        }
        return (int)ans;
    }
};
