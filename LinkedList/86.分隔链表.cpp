/*
 * @lc app=leetcode.cn id=86 lang=cpp
 *
 * [86] 分隔链表
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
    ListNode* partition(ListNode* head, int x) {
        ListNode* small = new ListNode(0, head);
        ListNode* smallHead = small;
        ListNode* large = new ListNode(0, head);
        ListNode* largeHead = large;
        while (head != nullptr) {
            if (head->val < x) {
                small->next = head;
                small = small->next;
            } else {
                large->next = head;
                large = large->next;
            }
            head = head->next;
        }
        large->next = nullptr;
        small->next = largeHead->next;
        return smallHead->next;
    }
};
// @lc code=end

//my error
ListNode* partition(ListNode* head, int x) {
    ListNode* firstLarge = nullptr, * cur = head;
    while (cur) {
        if (cur->val >= x) {
            firstLarge->next = cur;
            cur->next = cur->next->next;
        } else {
            cur = cur->next;
        }
    }
    cur->next = firstLarge->next;
    return cur;
}