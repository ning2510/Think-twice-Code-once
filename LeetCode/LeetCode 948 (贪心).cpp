/*
思路

如果让我们来玩令牌放置这个游戏，在让令牌正面朝上的时候，肯定要去找能量最小的令牌。同样的，在让令牌反面朝上的时候，肯定要去找能量最大的令牌。

算法

只要还有能量，就一直让令牌正面朝上，直到没有能量的时候，让一个令牌反面朝上从而获得能量继续之前的操作。

一定要小心处理边界条件，不然很有可能会写出错误的答案。这里要牢牢记住，在有能量时候，只能让令牌正面朝上，直到能量不够用了才能让令牌反面朝上。

最终答案一定是在一次让令牌正常朝上操作之后产生的（永远不可能在让令牌反面朝上操作之后产
*/

class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int P) {
        int ans = 0, now = 0, l = 0, r = tokens.size() - 1;
        sort(tokens.begin(), tokens.end());
        while(l <= r) {
            if(P < tokens[l]) {
                if(ans == 0) return 0;
                now--;
                P += tokens[r--];
            }
            else {
                now++;
                ans = max(ans, now);
                P -= tokens[l++];
            }
        }
        return ans;
    }
};