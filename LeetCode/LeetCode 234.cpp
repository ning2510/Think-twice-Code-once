/*************************************************************************
	> File Name: aaa.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年03月23日 星期一 17时39分36秒
 ************************************************************************/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// 反转前半部分
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(!head) return true;

        ListNode *fast = head, *low = head, *pre = NULL;
        //fast一次走两步，slow一次走一步
        //pre作用：反转链表充当slow的前驱指针

        //反转前半部分，slow和pre作为判断回文链表的双指针
        while(fast && fast->next) {
    //奇数链：slow位于链表中点，pre位于待判断的前半部分的第一位
    //偶数链：slow位于待判断的后半部分的第一位，pre位于待判断的前半部分的第一位
            fast = fast->next->next;
            ListNode *now = low->next;
            low->next = pre;    //反转
            pre = low;   //更新
            low = now;   //更新
        }
        if(fast) {   //判断是否为奇数链
            low = low->next;   //slow移动到待判断的后半部分的第一位
        }
        int flag = true;

        //判断回文
        while(pre && low) {
            if(pre->val != low->val) {
                flag = false;
                break;
            }
            pre = pre->next;
            low = low->next;
        }
        return flag;
    }
};

// 把链表存入数组判断
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode *p = head;
        int len = 1;
        vector <int> ss;
        if(p == NULL) return true;
        while(p->next) {
            len++;
            ss.push_back(p->val);
            p = p->next;
        }
        ss.push_back(p->val);
        int l = 0, r = len - 1;
        bool flag = true;
        while(l <= r) {
            if(ss[l] != ss[r]) {
                flag = false;
                break;
            }
            l++;
            r--;
        }
        return flag;
    }
};

