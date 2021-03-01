class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        unordered_map<int,int> diffCandies;
        for(int i:candyType) diffCandies[i]++;
        return min(diffCandies.size(),candyType.size()/2);
    }
};