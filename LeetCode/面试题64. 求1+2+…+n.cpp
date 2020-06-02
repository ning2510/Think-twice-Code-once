// 方法一：逻辑运算符 + 递归
class Solution {
public:
    int ans = 0;

    int sumNums(int n) {
        bool x = n > 1 && sumNums(n - 1) > 0;   //若 n <= 1，则不会进行 sumNums(0)
        ans += n;
        return ans;
    }
};

// 快速乘  使用while循环，不适用本题
class Solution {
public:
    int ksc(int a, int b) {
        int ans = 1, base = a;
        while(b > 0) {
            if(b & 1) ans += base;
            base += base;
            b >>= 1;
        }
        return ans;
    }

    int sumNums(int n) {
        return (ksc(1 + n, n) >> 1);
    }
};