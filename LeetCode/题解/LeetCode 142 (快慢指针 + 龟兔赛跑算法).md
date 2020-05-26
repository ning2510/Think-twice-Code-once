#### LeetCode 142 (快慢指针 + 龟兔赛跑算法)

#### 1. 解题思路

![](https://cdn.luogu.com.cn/upload/image_hosting/lowz9njl.png)

首先，我们设环长 L，则 L = y + z

**相遇时：**

slow 走过的路程：`x + y`

fast 走过的路程：`x + y + kL (k >= 0)`



又因为 slow 走一步，fast 走两步，故 `fast = 2 * slow`

即 `2 * (x + y) = x + y + kL`

又`L = y + z`

**化简得：**

`x = z + (k - 1)L`



所以当 slow 从起点到环起始点的距离等于 fast 从相遇点到环起始点的距离



#### 2. 代码实现

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) {
                slow = head;
                while(slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            }
        }
        return NULL;
    }
};
```



#### 3. 例题

**[LeetCode 287](https://leetcode-cn.com/problems/find-the-duplicate-number/)**



**代码实现**

```c
//方法一： 二分 时间：O(nlogn) 空间：O(1)
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = n - 1, cnt = 0, ans;
        while(l <= r) {
            int mid = (l + r) >> 1;
            cnt = 0;
            for(int i = 0; i < n; i++) {
                cnt += nums[i] <= mid;
            }
            if(cnt <= mid) {
                l = mid + 1;
            }
            else {
                r = mid - 1;
                ans = mid;
            }
        }
        return ans;
    }
};

//方法二： 快慢指针(龟兔赛跑算法) 时间：O(n) 空间：O(1)  类似LeetCode 142
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0], fast = nums[nums[0]];
        while(slow != fast) {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
        slow = 0;
        while(slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};

//方法三： 位运算  时间：O(nlogn) 空间：O(1)
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size(), max_bit = 31;
        while(!((n - 1) >> max_bit)) max_bit--;
        int ans = 0;
        for(int bit = 0; bit <= max_bit; bit++) {
            int x = 0, y = 0;
            for(int i = 0; i < n; i++) {
                if(nums[i] & (1 << bit)) x++;
                if(i >= 1 && (i & (1 << bit))) y++;
            }
            if(x > y) ans |= 1 << bit;
        }
        return ans;
    }
};
```

