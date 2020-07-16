class Solution {
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        int sum_a = 0, sum_b = 0;
        unordered_map <int, int> ss;
        for(auto &x : A) sum_a += x;
        for(auto &x : B) {
            sum_b += x;
            ss[x]++;
        }
        for(auto &x : A) {
            int y = (sum_b - sum_a + 2 * x) / 2;
            if(ss.count(y)) return {x, y};
        }
        return {};
    }
};