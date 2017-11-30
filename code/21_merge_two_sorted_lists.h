//
// Created by wcj on 17-11-15.
//

#ifndef LEETCODE_21_MERGE_TWO_SORTED_LISTS_H
#define LEETCODE_21_MERGE_TWO_SORTED_LISTS_H

//Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.

#include <cstdio>

namespace leetcode {
    class MergeTwoSortedLists {
    public:
        /**
         * Definition for singly-linked list.
         * struct ListNode {
         *     int val;
         *     ListNode *next;
         *     ListNode(int x) : val(x), next(NULL) {}
         * };
         */
        struct ListNode {
            int val;
            ListNode *next;
            ListNode(int x) : val(x), next(nullptr) {}
        };

        static ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
            if (l1 == nullptr)
                return l2;
            if (l2 == nullptr)
                return l1;

            ListNode *head = l1->val < l2->val ? l1 : l2;
            ListNode *cur = head;
            ListNode *p1 = l1, *p2 = l2;
            ListNode *min;
            for (; p1 != nullptr && p2 != nullptr; ) {
                if (p1->val < p2->val) {
                    min = p1;
                    p1 = p1->next;
                } else {
                    min = p2;
                    p2 = p2->next;
                }

                cur->next = min;
                cur = cur->next;
            }

            if (p1 == nullptr) cur->next = p2;
            if (p2 == nullptr) cur->next = p1;

            return head;
        }
    };
}

#endif //LEETCODE_21_MERGE_TWO_SORTED_LISTS_H
