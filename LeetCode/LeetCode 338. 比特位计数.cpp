// 方法一：动态规划 时间复杂度：O(n)
// 若 i 为奇数：i 比 i/2 多了一个1
// 若 i 为偶数：i 和 i/2 相等
class Solution {
public:
    vector<int> countBits(int num) {
        vector <int> ss(num + 1);
        for(int i = 1; i <= num; i++) {
            ss[i] = ss[i >> 1] + (i & 1);
        }
        return ss;
    }
};

/* 方法二：位运算 时间复杂度：O(n*sizeof(integer))
class Solution {
public:
    vector<int> countBits(int num) {
        vector <int> ss;
        ss.push_back(0);
        for(int i = 1; i <= num; i++) {
            int x = i, ans = 0;
            while(x) {
                x &= x - 1;
                ans++;
            }
            ss.push_back(ans);
        }
        return ss;
    }
};
*/