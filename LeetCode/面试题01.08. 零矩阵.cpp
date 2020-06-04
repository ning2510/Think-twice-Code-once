class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector <vector<int>> ss = matrix;
        for(int i = 0; i < ss.size(); i++) {
            for(int j = 0; j < ss[i].size(); j++) {
                if(ss[i][j] == 0) {
                    for(int k = 0; k < ss[i].size(); k++) {
                        matrix[i][k] = 0;
                    }
                    for(int k = 0; k < ss.size(); k++) {
                        matrix[k][j] = 0;
                    }
                }
            }
        }
    }
};