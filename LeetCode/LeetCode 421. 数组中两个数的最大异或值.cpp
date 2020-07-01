// 先确定高位，再确定低位（有点贪心算法的意思），才能保证这道题的最大性质
// 一位接着一位去确定这个数位的大小
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int res = 0, mask = 0;
        for(int i = 30; i >= 0; i--) {
            // 注意点1：注意保留前缀的方法，mask 是这样得来的
            mask |= (1 << i);
            set <int> ss;
            for(auto &x : nums) {
                // 注意点2：这里使用 & ，保留前缀的意思（从高位到低位）
                ss.insert(x & mask);
            }
            // 这里先假定第 n 位为 1 ，前 n-1 位 res 为之前迭代求得
            int temp = res | (1 << i);
            for(auto &x : ss) {
                if(ss.count(x ^ temp)) {
                    // 利用性质： a ^ b = c ，则 a ^ c = b，且 b ^ c = a
                    res = temp;
                    break;
                }
            }
        }
        return res;
    }
};