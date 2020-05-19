// 方法二：二分
class Solution {
public:
    int minArray(vector<int>& numbers) {
        int l = 0, r = numbers.size() - 1;
        while(l < r) {
            int mid = (l + r) >> 1;
            if(numbers[mid] > numbers[r]) l = mid + 1;
            else if(numbers[mid] < numbers[r]) r = mid;
            else r--;
        }
        return numbers[l];
    }
};

// 方法二：暴力
class Solution {
public:
    int minArray(vector<int>& numbers) {
        int ans = numbers[0];
        for(int i = 1; i < numbers.size(); i++) {
            ans = min(ans, numbers[i]);
        }
        return ans;
    }
};
