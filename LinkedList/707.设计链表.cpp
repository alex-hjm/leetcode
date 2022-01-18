/*
 * @lc app=leetcode.cn id=707 lang=cpp
 *
 * [707] 设计链表
 */

// @lc code=start
//单链表
class MyLinkedList {
public:
    struct LinkeNode {
        int val;
        LinkeNode* next;
        LinkeNode() :val(0), next(nullptr) {}
        LinkeNode(int x) :val(x), next(nullptr) {}
        LinkeNode(int x, LinkeNode* next) :val(x), next(next) {}
    };

    MyLinkedList() {
        _dummyNode = new LinkeNode;
        _size = 0;
    }

    int get(int index) {
        if (index > (_size - 1) || index < 0) {
            return -1;
        }
        LinkeNode* curr = _dummyNode->next;
        while (index--) {
            curr = curr->next;
        }
        return curr->val;
    }

    void addAtHead(int val) {
        LinkeNode* newHead = new LinkeNode(val);
        newHead->next = _dummyNode->next;
        _dummyNode->next = newHead;
        _size++;
    }

    void addAtTail(int val) {
        LinkeNode* curr = _dummyNode;
        while (curr->next) {
            curr = curr->next;
        }
        curr->next = new LinkeNode(val);
        _size++;
    }

    void addAtIndex(int index, int val) {
        if (index > _size) return;
        LinkeNode* curr = _dummyNode;
        while (index--) {
            curr = curr->next;
        }
        curr->next = new LinkeNode(val, curr->next);
        _size++;
    }

    void deleteAtIndex(int index) {
        if (index >= _size || index < 0)  return;
        LinkeNode* curr = _dummyNode;
        while (index--) {
            curr = curr->next;
        }
        LinkeNode* tmp = curr->next;
        curr->next = curr->next->next;
        delete tmp;
        _size--;
    }
private:
    LinkeNode* _dummyNode;
    int _size;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
// @lc code=end

struct LinkeNode {
    int val;
    LinkeNode* next;
    LinkeNode() :val(0), next(nullptr) {}
    LinkeNode(int x) :val(x), next(nullptr) {}
    LinkeNode(int x, LinkeNode* next) :val(x), next(next) {}
};

//my error
class MyLinkedList {
public:
    MyLinkedList() {
        head = new LinkeNode;
    }

    int get(int index) {
        LinkeNode* curr = head;
        int num = 0;
        while (curr) {
            if (index == num)
                return curr->val;
            ++num;
            curr = curr->next;
        }
        return -1;
    }

    void addAtHead(int val) {
        LinkeNode* newHead = new LinkeNode(val, head);
        head = newHead;
    }

    void addAtTail(int val) {
        LinkeNode* curr = head;
        while (curr) {
            curr = curr->next;
        }
        curr = new LinkeNode(val);
    }

    void addAtIndex(int index, int val) {
        if (index < 0) addAtHead(val);
        LinkeNode* curr = head;
        int num = 0;
        while (curr) {
            if (index == num) {
                curr->next = new LinkeNode(val, curr->next);
                return;
            }
            ++num;
            curr = curr->next;
        }
        if (index == num)
            addAtTail(val);
    }

    void deleteAtIndex(int index) {
        LinkeNode* dummp = new  LinkeNode(-1, head);
        LinkeNode* curr = dummp;
        int num = 0;
        while (curr && curr->next) {
            if (index == num) {
                LinkeNode* tmp = curr->next;
                curr->next = curr->next->next;
                delete tmp;
            } else {
                curr = curr->next;
            }
            ++num;
        }
        delete dummp;
    }
private:
    LinkeNode* head;
};

//单链表
class MyLinkedList {
public:

    MyLinkedList() = default;
    MyLinkedList(const MyLinkedList&) = delete;
    MyLinkedList(MyLinkedList&&) = delete;

    int get(int index) {
        LinkeNode* cur = head;
        if (index >= size || index < 0) return -1;
        while (index--)
            cur = cur->next;
        return cur->val;
    }

    void addAtHead(int val) {
        addAtIndex(0, val);
    }

    void addAtTail(int val) {
        addAtIndex(size, val);
    }

    void addAtIndex(int index, int val) {
        if (index > size || index < 0) return;
        LinkeNode** pcur = &head;
        while (index--)
            pcur = &((*pcur)->next);

        LinkeNode* new_node = new LinkeNode(val, *pcur);
        *pcur = new_node;
        size++;
    }

    void deleteAtIndex(int index) {
        if (index >= size || index < 0) return;
        LinkeNode** pcur = &head;
        while (index--)
            pcur = &((*pcur)->next);

        LinkeNode* tmp = *pcur;
        *pcur = (*pcur)->next;
        delete tmp;
        size--;
    }
    ~MyLinkedList() {
        while (head) {
            LinkeNode* tmp = head;
            head = head->next;
            delete tmp;
        }
    }
private:
    LinkeNode* head = nullptr;
    int size = 0;
};