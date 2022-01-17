#include "LinkedList.h"

ListNode* swapPairs(ListNode* head) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }
    ListNode* newHead = head->next;
    head->next = swapPairs(newHead->next);
    newHead->next = head;
    return newHead;
}

ListNode* deleteDuplicates(ListNode* head) {
    ListNode* cur = head;
    while (cur && cur->next) {
        if (cur->val == cur->next->val) {
            cur->next = cur->next->next;
        } else {
            cur = cur->next;
        }
    }
    return head;
}

ListNode* deleteDuplicates2(ListNode* head) {
    if (!head) return head;
    ListNode* dummy = new ListNode(-1, head);
    ListNode* cur = dummy;
    while (cur->next && cur->next->next) {
        if (cur->next->val == cur->next->next->val) {
            int x = cur->next->val;
            while (cur->next && cur->next->val == x)
                cur->next = cur->next->next;
        } else {
            cur = cur->next;
        }
    }
    return dummy->next;

}

ListNode* partition(ListNode* head, int x) {
    ListNode* large = new ListNode, * next = large;
    ListNode* cur = head;
    while (cur && cur->next) {
        if (cur->val >= x) {
            next->next = cur;
            cur = cur->next->next;
            next = next->next;
        } else {
            cur = cur->next;
        }
    }
    cur->next = large->next;
    return cur;
}
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
        int sum = a + b;
        if (sum >= 10)
            val = 1;
        else
            val = 0;
        cur->next = new ListNode(sum % 10);
        cur = cur->next;
    }
    return sumNode->next;
}
ListNode* sortList(ListNode* head) {
    while (head == nullptr || head->next == nullptr) {
        return head;
    }
    head->next = sortList(head->next);
    if (head->val > head->next->val) {
        head->next = head;
        return head->next;
    } else
        return head;

}

void print(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    //ListNode* head7 = new ListNode(4, nullptr);
    ListNode* head6 = new ListNode(2, nullptr);
    ListNode* head5 = new ListNode(0, head6);
    ListNode* head4 = new ListNode(5, head5);
    ListNode* head3 = new ListNode(3, head4);
    ListNode* head2 = new ListNode(4, head3);
    ListNode* head1 = new ListNode(-1, head2);
    print(sortList(head1));
}
