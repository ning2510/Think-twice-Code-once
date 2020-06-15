class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& A) {
        vector <vector<int>> ss;
        int n = A.size();
        if(n == 0) return ss;
        int m = A[0].size();
        ss.resize(m, vector <int> (n, 0));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                ss[j][i] = A[i][j];
            }
        }
        return ss;
    }
};