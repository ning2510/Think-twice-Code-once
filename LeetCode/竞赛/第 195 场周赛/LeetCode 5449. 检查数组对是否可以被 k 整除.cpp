class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map <int, int> ss;
        for(auto &x : arr) {
            x = ((x % k) + k) % k;
            ss[x]++;
        }
        if(ss[0] & 1) return false;
        for(int i = 1; i <= k / 2; i++) {
            if((ss[i] + ss[k - i]) & 1) return false;
        }
        return true;
    }
};