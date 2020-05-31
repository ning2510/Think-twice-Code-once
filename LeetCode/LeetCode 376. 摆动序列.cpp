// 方法一：时间复杂度：O(n^2)  空间：O(n)
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        if(n < 2) return n;
        int up[n + 5], down[n + 5];
        memset(up, 0, sizeof(up));
        memset(down, 0, sizeof(down));
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(nums[i] > nums[j]) {
                    up[i] = max(up[i], down[j] + 1);
                }
                else if(nums[i] < nums[j]) {
                    down[i] = max(down[i], up[j] + 1);
                }
            }
        }
        return max(up[n - 1], down[n - 1]) + 1;
    }
};

// 方法二： 时间复杂度: O(n)  空间: O(n)
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        if(n < 2) return n;
        int up[n + 5], down[n + 5];
        memset(up, 0, sizeof(up));
        memset(down, 0, sizeof(down));
        up[0] = down[0] = 1;
        for(int i = 1; i < n; i++) {
            if(nums[i] > nums[i - 1]) {
                up[i] = down[i - 1] + 1;
                down[i] = down[i - 1];
            }
            else if(nums[i] < nums[i - 1]) {
                up[i] = up[i - 1];
                down[i] = up[i - 1] + 1;
            }
            else {
                up[i] = up[i - 1];
                down[i] = down[i - 1];
            }
        }
        return max(up[n - 1], down[n - 1]);
    }
};

// 方法三： 时间复杂度: O(n)  空间: O(1)
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        if(n < 2) return n;
        int up = 1, down = 1;
        for(int i = 1; i < n; i++) {
            if(nums[i] > nums[i - 1]) {
                up = down + 1;
            }
            else if(nums[i] < nums[i - 1]) {
                down = up + 1;
            }
        }
        return max(up, down);
    }
};