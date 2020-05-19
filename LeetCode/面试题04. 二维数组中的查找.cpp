//方法一：从右上角开始搜索  80ms
class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        if(matrix.size() == 0) return false;
        int n = matrix.size(), m = matrix[0].size();
        int now_x = 0, now_y = m - 1;
        while(now_x < n && now_y >= 0) {
            if(matrix[now_x][now_y] == target) return true;
            else if(matrix[now_x][now_y] < target) now_x++;
            else now_y--;
        }
        return false;
    }
};

// 方法二：暴力  52ms
class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        for(int i = 0; i < matrix.size(); i++) {
            for(int j = 0; j < matrix[i].size(); j++) {
                if(matrix[i][j] == target) return true;
            }
        }
        return false;
    }
};
