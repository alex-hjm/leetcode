/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = nullptr, * tail = nullptr;
        int carry = 0;
        while (l1 || l2) {
            int n1 = l1 ? l1->val : 0;
            int n2 = l2 ? l2->val : 0;
            int sum = n1 + n2 + carry;
            if (!head) {
                head = tail = new ListNode(sum % 10);
            } else {
                tail->next = new ListNode(sum % 10);
                tail = tail->next;
            }
            carry = sum / 10;
            if (l1) {
                l1 = l1->next;
            }
            if (l2) {
                l2 = l2->next;
            }
        }
        if (carry > 0) {
            tail->next = new ListNode(carry);
        }
        return head;
    }
};
// @lc code=end

//my
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* sumNode = new ListNode(0), * cur = sumNode;
    int val = 0;
    while (l1 || l2) {
        int a = 0, b = 0;
        if (l1) {
            a = l1->val;
            l1 = l1->next;
        }
        if (l2) {
            b = l2->val;
            l2 = l2->next;
        }
        int sum = a + b + val;
        if (sum >= 10)
            val = 1;
        else
            val = 0;
        cur->next = new ListNode(sum % 10);
        cur = cur->next;
    }
    if (val != 0)
        cur->next = new ListNode(1);
    return sumNode->next;
}