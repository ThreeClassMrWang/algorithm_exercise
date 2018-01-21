//
// Created by wcj on 1/9/18.
//

#ifndef LEETCODE_19_REMOVED_NTH_NODE_FROM_END_OF_LIST_H
#define LEETCODE_19_REMOVED_NTH_NODE_FROM_END_OF_LIST_H

//Given a linked list, remove the nth node from the end of list and return its head.
//
//For example,
//
//        Given linked list: 1->2->3->4->5, and n = 2.
//
//After removing the second node from the end, the linked list becomes 1->2->3->5.
//Note:
//        Given n will always be valid.
//Try to do this in one pass.

struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) : val(x), next(nullptr) { }
};

namespace leetcode {
class RemoveNthFromEnd {
public:
    static ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head) return nullptr;

        ListNode* target = nullptr;
        ListNode* p = head;
        for (int i = 0; p; p = p->next, i++) {
            if (i == n)
                target = head;
            else if (i > n )
                target = target->next;
        }

        // Given n is correct, this is delete head
        // maybe memory leak, but i don't known how to delete this.
        if (!target) {
            return head->next;
        } else {
            target->next = target->next->next;
            return head;
        }
    }
};
}

#endif //LEETCODE_19_REMOVED_NTH_NODE_FROM_END_OF_LIST_H
