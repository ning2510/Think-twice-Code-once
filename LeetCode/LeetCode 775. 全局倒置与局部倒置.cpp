// 方法一：记录最小值
class Solution {
public:
    bool isIdealPermutation(vector<int>& A) {
        int minx = A.size();
        for(int i = A.size() - 1; i >= 2; i--) {
            minx = min(minx, A[i]);
            if(A[i - 2] > minx) return false;
        }
        return true;
    }
};

// 方法二：线性搜索
class Solution {
public:
    bool isIdealPermutation(vector<int>& A) {
        for(int i = 0; i < A.size(); i++) {
            if(abs(A[i] - i) > 1) return false;
        }
        return true;
    }
};