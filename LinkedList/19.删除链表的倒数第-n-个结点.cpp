/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第 N 个结点
 *
 * https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list/description/
 *
 * algorithms
 * Medium (43.35%)
 * Likes:    1750
 * Dislikes: 0
 * Total Accepted:    615.8K
 * Total Submissions: 1.4M
 * Testcase Example:  '[1,2,3,4,5]\n2'
 *
 * 给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：head = [1,2,3,4,5], n = 2
 * 输出：[1,2,3,5]
 *
 *
 * 示例 2：
 *
 *
 * 输入：head = [1], n = 1
 * 输出：[]
 *
 *
 * 示例 3：
 *
 *
 * 输入：head = [1,2], n = 1
 * 输出：[1]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 链表中结点的数目为 sz
 * 1 <= sz <= 30
 * 0 <= Node.val <= 100
 * 1 <= n <= sz
 *
 *
 *
 *
 * 进阶：你能尝试使用一趟扫描实现吗？
 *
 */
#include "LinkedList.h"
// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* first = head;
        ListNode* second = dummy;
        for (int i = 0;i < n;i++) 
            first=first->next;
        while (first){
            first=first->next;
            second=second->next;
        }
        second->next=second->next->next;
        ListNode* ans = dummy->next;
        delete dummy;
        return ans;
    }
};
// @lc code=end

//my
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* p1, * p2 = head;
        for (int i = 0;i < n;i++) {
            if (p1->next)
                p1 = p1->next;
        }
        while (p1->next) {
            p1 = p1->next;
            p2 = p2->next;
        }

    }
};

//方法一：计算链表长度
class Solution {
public:
    int getLength(ListNode* head) {
        ListNode* p = head;
        int length = 0;
        while (p) {
            p = p->next;
            ++length;
        }
        return length;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int length = getLength(head);
        ListNode* dummy = new ListNode(0, head);
        ListNode* cur = dummy;
        for (int i = 0;i < length - n + 1;++i) {
            cur = cur->next;
        }
        cur->next = cur->next->next;
        ListNode* ans = dummy->next;
        delete dummy;
        return ans;
    }
};

//方法二：栈
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0, head);
        stack<ListNode*> stk;
        ListNode* cur = dummy;
        while (cur) {
            stk.push(cur);
            cur = cur->next;
        }
        for (int i = 0;i < n;i++)
            stk.pop();
        ListNode* prev = stk.top();
        prev->next = prev->next->next;
        ListNode* ans = dummy->next;
        delete dummy;
        return ans;
    }
};

//方法三：双指针
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* first = head;
        ListNode* second = dummy;
        for (int i = 0;i < n;i++) 
            first=first->next;
        while (first){
            first=first->next;
            second=second->next;
        }
        second->next=second->next->next;
        ListNode* ans = dummy->next;
        delete dummy;
        return ans;
    }
};

