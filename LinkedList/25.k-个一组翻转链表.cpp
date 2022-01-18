/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] K 个一组翻转链表
 *
 * https://leetcode-cn.com/problems/reverse-nodes-in-k-group/description/
 *
 * algorithms
 * Hard (65.92%)
 * Likes:    1429
 * Dislikes: 0
 * Total Accepted:    262.1K
 * Total Submissions: 397.6K
 * Testcase Example:  '[1,2,3,4,5]\n2'
 *
 * 给你一个链表，每 k 个节点一组进行翻转，请你返回翻转后的链表。
 *
 * k 是一个正整数，它的值小于或等于链表的长度。
 *
 * 如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。
 *
 * 进阶：
 *
 *
 * 你可以设计一个只使用常数额外空间的算法来解决此问题吗？
 * 你不能只是单纯的改变节点内部的值，而是需要实际进行节点交换。
 *
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：head = [1,2,3,4,5], k = 2
 * 输出：[2,1,4,3,5]
 *
 *
 * 示例 2：
 *
 *
 * 输入：head = [1,2,3,4,5], k = 3
 * 输出：[3,2,1,4,5]
 *
 *
 * 示例 3：
 *
 *
 * 输入：head = [1,2,3,4,5], k = 1
 * 输出：[1,2,3,4,5]
 *
 *
 * 示例 4：
 *
 *
 * 输入：head = [1], k = 1
 * 输出：[1]
 *
 *
 *
 *
 *
 * 提示：
 *
 *
 * 列表中节点的数量在范围 sz 内
 * 1
 * 0
 * 1
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
    pair<ListNode*, ListNode*> myReverse(ListNode* head, ListNode* tail) {
        ListNode* prev = tail->next;
        ListNode* curr = head;
        while (prev != tail) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return { tail,head };
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* hair = new ListNode(0, head);
        ListNode* pre = hair;

        while (head) {
            ListNode* tail = pre;
            for (int i = 0; i < k; ++i) {
                tail = tail->next;
                if (!tail) {
                    return hair->next;
                }
            }
            ListNode* nex = tail->next;
            // 这里是 C++17 的写法，也可以写成
            // pair<ListNode*, ListNode*> result = myReverse(head, tail);
            // head = result.first;
            // tail = result.second;
            tie(head, tail) = myReverse(head, tail);
            pre->next = head;
            tail->next = nex;
            pre = tail;
            head = tail->next;
        }
        return hair->next;
    }
};
// @lc code=end


//递归
ListNode* reverseList(ListNode* head, ListNode* tail) {
    ListNode* prev = nullptr;
    ListNode* curr = head;
    while (curr != tail) {
        ListNode* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

ListNode* reverseKGroup(ListNode* head, int k) {
    if (head == nullptr) return nullptr;
    ListNode* start = head, * end = head;
    //base case
    for (int i = 0;i < k;i++) {
        if (end == nullptr) return head;
        end = end->next;
    }
    ListNode* newHead = reverseList(start, end);
    start->next = reverseKGroup(end, k);
    return newHead;
}

//模拟：
pair<ListNode*, ListNode*> myReverse(ListNode* head, ListNode* tail) {
    ListNode* prev = tail->next;
    ListNode* curr = head;
    while (prev != tail) {
        ListNode* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return { tail,head };
}

ListNode* reverseKGroup(ListNode* head, int k) {
    ListNode* hair = new ListNode(0, head);
    ListNode* pre = hair;

    while (head) {
        ListNode* tail = pre;
        for (int i = 0; i < k; ++i) {
            tail = tail->next;
            if (!tail) {
                return hair->next;
            }
        }
        ListNode* nex = tail->next;
        // 这里是 C++17 的写法，也可以写成
        // pair<ListNode*, ListNode*> result = myReverse(head, tail);
        // head = result.first;
        // tail = result.second;
        tie(head, tail) = myReverse(head, tail);
        pre->next = head;
        tail->next = nex;
        pre = tail;
        head = tail->next;
    }
    return hair->next;
}