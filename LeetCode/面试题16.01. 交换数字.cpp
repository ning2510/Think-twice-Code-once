// 方法一：减法
class Solution {
public:
    vector<int> swapNumbers(vector<int>& numbers) {
        numbers[0] -= numbers[1];
        numbers[1] += numbers[0];
        numbers[0] = numbers[1] - numbers[0];
        return numbers;
    }
};

// 方法二：加法
class Solution {
public:
    vector<int> swapNumbers(vector<int>& numbers) {
        numbers[0] += numbers[1];
        numbers[1] = numbers[0] - numbers[1];
        numbers[0] -= numbers[1];
        return numbers;
    }
};


// 方法三：异或
class Solution {
public:
    vector<int> swapNumbers(vector<int>& numbers) {
        numbers[0] ^= numbers[1];
        numbers[1] ^= numbers[0];
        numbers[0] ^= numbers[1];
        return numbers;
    }
};
