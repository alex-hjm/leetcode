/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并K个升序链表
 *
 * https://leetcode-cn.com/problems/merge-k-sorted-lists/description/
 *
 * algorithms
 * Hard (56.27%)
 * Likes:    1689
 * Dislikes: 0
 * Total Accepted:    372.4K
 * Total Submissions: 661.9K
 * Testcase Example:  '[[1,4,5],[1,3,4],[2,6]]'
 *
 * 给你一个链表数组，每个链表都已经按升序排列。
 *
 * 请你将所有链表合并到一个升序链表中，返回合并后的链表。
 *
 *
 *
 * 示例 1：
 *
 * 输入：lists = [[1,4,5],[1,3,4],[2,6]]
 * 输出：[1,1,2,3,4,4,5,6]
 * 解释：链表数组如下：
 * [
 * ⁠ 1->4->5,
 * ⁠ 1->3->4,
 * ⁠ 2->6
 * ]
 * 将它们合并到一个有序链表中得到。
 * 1->1->2->3->4->4->5->6
 *
 *
 * 示例 2：
 *
 * 输入：lists = []
 * 输出：[]
 *
 *
 * 示例 3：
 *
 * 输入：lists = [[]]
 * 输出：[]
 *
 *
 *
 *
 * 提示：
 *
 *
 * k == lists.length
 * 0 <= k <= 10^4
 * 0 <= lists[i].length <= 500
 * -10^4 <= lists[i][j] <= 10^4
 * lists[i] 按 升序 排列
 * lists[i].length 的总和不超过 10^4
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
    //顺序合并
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head = new ListNode(-1), * p = head;
        ListNode* first = list1, * second = list2;
        while (first != nullptr && second != nullptr) {
            if (first->val < second->val) {
                p->next = first;
                first = first->next;
            } else {
                p->next = second;
                second = second->next;
            }
            p = p->next;
        }
        if (first != nullptr)p->next = first;
        if (second != nullptr)p->next = second;
        return  head->next;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* ans = nullptr;
        for (auto& i : lists)
            ans = mergeTwoLists(ans, i);
        return ans;
    }
};
// @lc code=end

//my
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) return nullptr;
        ListNode* head = lists.front(), * prev = head;
        for (auto& p : lists) {
            if (prev->val <= p->val) {
                prev->next = p;
                p = p->next;
            } else {

            }
            prev = prev->next;
        }
    }
};

//分治合并
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head = new ListNode(-1), * p = head;
        ListNode* first = list1, * second = list2;
        while (first != nullptr && second != nullptr) {
            if (first->val < second->val) {
                p->next = first;
                first = first->next;
            } else {
                p->next = second;
                second = second->next;
            }
            p = p->next;
        }
        if (first != nullptr)p->next = first;
        if (second != nullptr)p->next = second;
        return  head->next;
    }

    ListNode* merge(vector <ListNode*>& lists, int l, int r) {
        if (l == r) return lists[l];
        if (l > r) return nullptr;
        int mid = (l + r) >> 1;
        return mergeTwoLists(merge(lists, l, mid), merge(lists, mid + 1, r));
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return merge(lists, 0, lists.size() - 1);
    }
};

//使用优先队列合并
class Solution {
public:
    struct Status {
        int val;
        ListNode* ptr;
        bool operator < (const Status& rhs) const { //小顶堆
            return val > rhs.val;
        }
    };

    priority_queue<Status> q;

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        for(auto node:lists)
            q.push({node->val,node});
        ListNode head, *tail = &head;
        while(!q.empty()) {
            auto f=q.top();q.pop();
            tail->next=f.ptr;
            tail=tail->next;
            if(f.ptr->next)
                q.push({f.ptr->next->val, f.ptr->next});
        }
        return head.next;
    }
};
