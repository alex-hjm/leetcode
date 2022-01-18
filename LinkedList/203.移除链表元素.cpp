/*
 * @lc app=leetcode.cn id=203 lang=cpp
 *
 * [203] 移除链表元素
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
    ListNode* removeElements(ListNode* head, int val) {
        if (head == nullptr) return head;
        head->next = removeElements(head->next, val);
        return head->val == val ? head->next : head;
    }
};
// @lc code=end

//my error
ListNode* removeElements(ListNode* head, int val) {
    ListNode* pre = new ListNode(-1, head);
    while (pre) {
        if (pre->next && pre->next->val == val) {
            pre->next = pre->next->next;
            pre = pre->next;
        }
        return pre->next;
    }
}

//直接使用原来的链表来进行移除节点操作
ListNode* removeElements(ListNode* head, int val) {
    while (head != nullptr && head->val == val) {
        ListNode* tmp = head;
        head = head->next;
        delete tmp;
    }
    ListNode* curr = head;
    while (curr && curr->next) {
        if (curr->next->val == val) {
            ListNode* tmp = curr->next;
            curr->next = curr->next->next;
            delete tmp;
        } else {
            curr = curr->next;
        }
    }
    return head;
}

//设置一个虚拟头结点在进行移除节点操作
ListNode* removeElements(ListNode* head, int val) {
    ListNode* dummy = new ListNode(-1, head);
    ListNode* curr = dummy;
    while (curr && curr->next) {
        if (curr->next->val == val) {
            ListNode* tmp = curr->next;
            curr->next = curr->next->next;
            delete tmp;
        } else {
            curr = curr->next;
        }
    }
    ListNode* ans = dummy->next;
    delete dummy;
    return ans;
}

//递归
ListNode* removeElements(ListNode* head, int val) {
    if (head == nullptr) return head;
    head->next = removeElements(head->next, val);
    return head->val == val ? head->next : head;
}