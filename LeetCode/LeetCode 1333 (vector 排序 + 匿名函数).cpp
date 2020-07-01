class Solution {
public:
    vector<int> filterRestaurants(vector<vector<int>>& restaurants, int veganFriendly, int maxPrice, int maxDistance) {
        vector <vector<int>> ss;
        for(int i = 0; i < restaurants.size(); i++) {
            if(restaurants[i][3] > maxPrice || restaurants[i][4] > maxDistance) continue;
            if(veganFriendly && !restaurants[i][2]) continue;
            ss.push_back(restaurants[i]);
        }
        sort(ss.begin(), ss.end(), [](const auto &x, const auto &y) {
            return (x[1] > y[1] || (x[1] == y[1] && x[0] > y[0]));
        });
        vector <int> ans;
        for(int i = 0; i < ss.size(); i++) {
            ans.push_back(ss[i][0]);
        }
        return ans;
    }
};