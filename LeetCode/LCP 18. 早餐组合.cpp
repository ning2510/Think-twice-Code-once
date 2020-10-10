class Solution {
public:
    const int mod = 1e9 + 7;
    
    int breakfastNumber(vector<int>& a, vector<int>& b, int x) {
        int ans = 0;
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        for(int i = 0; i < a.size(); i++) {
            if(a[i] >= x) break;
            int c = x - a[i];
            int it = upper_bound(b.begin(), b.end(), c) - b.begin();
            ans = (ans + it) % mod;
        }
        return ans;
    }
};