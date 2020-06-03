class Solution {
public:
    typedef long long ll;

    int strToInt(string str) {
        int now = 0, flag = 0;
        while(str[now] == ' ') now++;
        if(str[now] == '-') {
            flag = 1;
            now++;
        }
        else if(str[now] == '+') now++;
        else {
            if(str[now] < '0' || str[now] > '9') return 0;
        }
        ll sum = 0;
        while(str[now] >= '0' && str[now] <= '9') {
            sum = sum * 10 + str[now] - '0';
            if(!flag && sum >= INT_MAX) return INT_MAX;
            if(flag && sum * -1 <= INT_MIN) return INT_MIN;
            now++;
        }
        if(flag) sum = -sum;
        return sum;
    }
};