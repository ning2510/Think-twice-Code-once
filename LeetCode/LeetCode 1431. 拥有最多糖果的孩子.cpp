class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maxn = 0;
        for(int i = 0; i < candies.size(); i++) {
            maxn = max(maxn, candies[i]);
        }
        vector <bool> ss;
        for(int i = 0; i < candies.size(); i++) {
            if(candies[i] + extraCandies >= maxn) ss.push_back(true);
            else ss.push_back(false);
        }
        return ss;
    }
};