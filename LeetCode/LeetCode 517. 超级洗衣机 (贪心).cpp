/*
用当前值减去平均值【差值】，就是每个洗衣机要传入或者传出的数量，正数表示要传出，负数表示要传入
对于第i个洗衣机来说，左边要传入或者传出的数量，就是左边所有洗衣机的差值之和，为正表示左边有剩余，需要传到右边，为负表示左边不够，需要右边传过来，不管哪种情况，都要经过i节点，算作【流量】
差值 与 流量 的最大值，就是当前洗衣机要传入或者传出的数量
遍历所有洗衣机，找出最大值，即为最少次数

*/

class Solution {
public:
    int findMinMoves(vector<int>& machines) {
        int sum = 0, n = machines.size();
        for(auto &x : machines) sum += x;
        if(sum % n) return -1;
        sum /= n;
        int max_sum, ans = 0, now = 0;
        for(auto &x : machines) {
            now += x - sum;
            max_sum = max(x - sum, abs(now));
            ans = max(ans, max_sum);
        }
        return ans;
    }
};