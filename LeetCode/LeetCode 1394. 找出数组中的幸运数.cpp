class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map <int, int> ss;
        int ans = -1;
        for(auto &x : arr) {
            ss[x]++;
        }
        for(auto &x : arr) {
            if(ss[x] == x) ans = max(ans, x);
        }
        return ans;
    }
};