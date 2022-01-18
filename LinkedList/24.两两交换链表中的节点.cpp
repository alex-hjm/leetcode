/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
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
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode* newHead = head->next;
        head->next = swapPairs(newHead->next);
        newHead->next = head;
        return newHead;
    }
};
// @lc code=end

//迭代
ListNode* swapPairs(ListNode* head) {
    ListNode* dummy = new ListNode(-1, head);
    ListNode* cur = dummy;
    while (cur->next && cur->next->next) {
        ListNode* tmp = cur->next;
        ListNode* tmp1 = cur->next->next;

        cur->next = tmp1;
        tmp->next = tmp1->next;
        tmp1->next = tmp;
        cur = tmp;
    }
    return dummy->next;
}

//递归
ListNode* swapPairs(ListNode* head) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }
    ListNode* newHead = head->next;
    head->next = swapPairs(newHead->next);
    newHead->next = head;
    return newHead;
}