/*
 * @lc app=leetcode.cn id=876 lang=cpp
 *
 * [876] 链表的中间结点
 *
 * https://leetcode-cn.com/problems/middle-of-the-linked-list/description/
 *
 * algorithms
 * Easy (70.58%)
 * Likes:    475
 * Dislikes: 0
 * Total Accepted:    186.2K
 * Total Submissions: 263.8K
 * Testcase Example:  '[1,2,3,4,5]'
 *
 * 给定一个头结点为 head 的非空单链表，返回链表的中间结点。
 * 
 * 如果有两个中间结点，则返回第二个中间结点。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：[1,2,3,4,5]
 * 输出：此列表中的结点 3 (序列化形式：[3,4,5])
 * 返回的结点值为 3 。 (测评系统对该结点序列化表述是 [3,4,5])。
 * 注意，我们返回了一个 ListNode 类型的对象 ans，这样：
 * ans.val = 3, ans.next.val = 4, ans.next.next.val = 5, 以及 ans.next.next.next
 * = NULL.
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：[1,2,3,4,5,6]
 * 输出：此列表中的结点 4 (序列化形式：[4,5,6])
 * 由于该列表有两个中间结点，值分别为 3 和 4，我们返回第二个结点。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 给定链表的结点数介于 1 和 100 之间。
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
    ListNode* middleNode(ListNode* head) {
       ListNode* p=head;
       int length=0;
       while (p){
           ++length;
           p=p->next;
       }
       for(int i=0;i<length/2;i++) 
           head=head->next;
        return head;
    }
};
// @lc code=end

//my
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow =new ListNode(0,head);
        ListNode* fast=head;
        while (fast)
        {
            fast=fast->next->next;
            slow=slow->next;
        }
        ListNode* ans = slow->next;
        delete slow;
        return ans;
    }
};

//数组
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
       vector<ListNode*> vec={head};
       while (vec.back()->next)
           vec.push_back(vec.back()->next);
       return vec[vec.size()/2];
    }
};

//单指针
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
       ListNode* p=head;
       int length=0;
       while (p){
           ++length;
           p=p->next;
       }
       for(int i=0;i<length/2;i++) 
           head=head->next;
        return head;
    }
};

//快慢指针
    ListNode* middleNode(ListNode* head) {
        ListNode* slow=head ,*fast=head;
        while (fast&&fast->next)
        {
           fast=fast->next->next;
           slow=slow->next;
        }
        return slow;  
    }