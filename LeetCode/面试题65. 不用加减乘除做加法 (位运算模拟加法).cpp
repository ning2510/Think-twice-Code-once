class Solution {
public:
    int add(int a, int b) {
        // 异或 ^：可以模拟无进位的加操作
        // 按位与 &： 可以模拟进位的情况
        //这里只是进位变成unsigned int了，然后左移符号位就没了，如果不用unsigned int的话，数字太大太小编译器会报错，不然不用也没事
        unsigned int x = a & b;
        int y = a ^ b;
        while(x) {
            x <<= 1;
            int t = x & y;
            y ^= x;
            x = t;
        }
        return y;

        /* 简便写法，原理相同
        // 无进位和、进位值
        int sum, carry;
        while (b != 0) {
            // 异或操作得无进位和
            sum = a ^ b;
            // 与操作后移位得进位值
            carry = ((unsigned int) (a & b) << 1);

            // 循环，直到进位为0
            a = sum;
            b = carry;
        }
        return a;
        */
    }
};