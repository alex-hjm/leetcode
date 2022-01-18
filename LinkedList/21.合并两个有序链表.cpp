/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
 *
 * https://leetcode-cn.com/problems/merge-two-sorted-lists/description/
 *
 * algorithms
 * Easy (66.69%)
 * Likes:    2139
 * Dislikes: 0
 * Total Accepted:    822.9K
 * Total Submissions: 1.2M
 * Testcase Example:  '[1,2,4]\n[1,3,4]'
 *
 * 将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：l1 = [1,2,4], l2 = [1,3,4]
 * 输出：[1,1,2,3,4,4]
 *
 *
 * 示例 2：
 *
 *
 * 输入：l1 = [], l2 = []
 * 输出：[]
 *
 *
 * 示例 3：
 *
 *
 * 输入：l1 = [], l2 = [0]
 * 输出：[0]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 两个链表的节点数目范围是 [0, 50]
 * -100
 * l1 和 l2 均按 非递减顺序 排列
 *
 *
 */

 //Definition for singly-linked list.
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
//note: 1. 递归  2. 迭代（暴力）
class Solution {
public:
    //迭代
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head = new ListNode(-1), * p = head;
        ListNode* first = list1, * second = list2;
        while (first != nullptr && second != nullptr) {
            if (first->val < second->val) {
                p->next = first;
                first = first->next;
            }
            else {
                p->next = second;
                second = second->next;
            }
            p = p->next;
        }
        if (first != nullptr)
            p->next = first;
        if (second != nullptr)
            p->next = second;
        return  head->next;
    }
};
// @lc code=end

//my
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* list = new ListNode;
        list->val = list1->val < list2->val ? list1->val : list2->val;
        ListNode* first = list1->next;
        ListNode* second = list2->next;
        ListNode* list_next = list->next;
        while (first != nullptr && second != nullptr) {
            if (first->val < second->val) {
                list_next = new ListNode;
                list_next->val = first->val;
                first = first->next;
                list_next = list_next->next;
            }
            else {
                list_next = new ListNode;
                list_next->val = second->val;
                second = second->next;
                list_next = list_next->next;
            }
        }
        return  list;
    }
};

//递归
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1) return list2;
        else if(!list2) return list1;
        else if(list1->val<list2->val) {
            list1->next=mergeTwoLists(list1->next,list2);
            return list1;
        }
        else {
            list2->next=mergeTwoLists(list2->next,list1);
            return list2;
        }
    }
};
//==>
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (!list1 || list2 && list1->val > list2->val) swap(list1, list2);
        if (list1) list1->next = mergeTwoLists(list1->next, list2);
        return list1;
    }
};