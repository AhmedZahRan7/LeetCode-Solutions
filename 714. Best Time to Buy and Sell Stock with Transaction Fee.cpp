class Solution {
public:
    int maxProfit(vector<int>& P, int F) {
        int n = P.size() ;
        int buy = 0 ;
        int sell = -P[0];
        for (int i = 1; i < n; i++) {
            buy = max(buy, sell + P[i] - F);
            sell = max(sell, buy - P[i]);
        }
        return buy;
    }
};