/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
 *
 * https://leetcode-cn.com/problems/reverse-linked-list/description/
 *
 * algorithms
 * Easy (72.51%)
 * Likes:    2199
 * Dislikes: 0
 * Total Accepted:    826.3K
 * Total Submissions: 1.1M
 * Testcase Example:  '[1,2,3,4,5]'
 *
 * 给你单链表的头节点 head ，请你反转链表，并返回反转后的链表。
 *
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：head = [1,2,3,4,5]
 * 输出：[5,4,3,2,1]
 *
 *
 * 示例 2：
 *
 *
 * 输入：head = [1,2]
 * 输出：[2,1]
 *
 *
 * 示例 3：
 *
 *
 * 输入：head = []
 * 输出：[]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 链表中节点的数目范围是 [0, 5000]
 * -5000
 *
 *
 *
 *
 * 进阶：链表可以选用迭代或递归方式完成反转。你能否用两种方法解决这道题？
 *
 *
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
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode* last = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return last;
    }
};
// @lc code=end

//my
ListNode* reverseList(ListNode* head) {
    vector<ListNode*> vec = { head };
    while (head) {
        head = head->next;
        vec.push_back(head);
    }
    ListNode* ans = new ListNode;
    for (int i = vec.size() - 1;i > -1;i--) {
        ans->next = vec[i];
        ans = ans->next;
    }
    return ans->next;
}

//迭代
ListNode* reverseList(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* curr = head;
    while (curr) {
        ListNode* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

//递归
ListNode* reverseList(ListNode* head) {
    if (head == nullptr || head->next == nullptr)
        return head;
    ListNode* last = reverseList(head->next);
    head->next->next = head;
    head->next = nullptr;
    return last;
}

ListNode *successor =nullptr;
//反转链表前N个节点
ListNode* reverseNthList(ListNode* head,int n) {
    if(n==1) {
        successor=head->next;
        return head;
    }
    ListNode* last=reverseNthList(head->next,n-1);
    head->next->next = head;
    head->next = successor;
    return last;
}