class Solution {
public:
    vector<int> closestDivisors(int num) {
        int x = sqrt(num + 1), y = sqrt(num + 2);
        while((num + 1) % x != 0) x--;
        while((num + 2) % y != 0) y--;
        int x1 = (num + 1) / x;
        int y1 = (num + 2) / y;
        if(abs(x1 - x) > abs(y1 - y)) {
            x = y;
            x1 = y1;
        }
        return {x, x1};
    }
};