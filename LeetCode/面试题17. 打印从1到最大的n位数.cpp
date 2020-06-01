class Solution {
public:
    vector<int> printNumbers(int n) {
        int m = pow(10, n) - 1;
        vector <int> ss;
        for(int i = 1; i <= m; i++) {
            ss.push_back(i);
        }
        return ss;
    }
};