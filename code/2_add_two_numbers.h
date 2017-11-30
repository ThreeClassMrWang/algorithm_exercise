//
// Created by wcj on 17-11-16.
//

#ifndef LEETCODE_2_ADD_TWO_NUMBERS_H
#define LEETCODE_2_ADD_TWO_NUMBERS_H

//You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
//
//You may assume the two numbers do not contain any leading zero, except the number 0 itself.
//
//Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
//Output: 7 -> 0 -> 8

// FIXME : will cause memory leak, input list can not be free correctly.

namespace leetcode {
    class AddTwoNumbers {
    public:
        struct ListNode {
            int val;
            ListNode *next;
            ListNode(int x) : val(x), next(nullptr) {}
        };

        static ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
            if (l1 == nullptr) return l2;
            else if (l2 == nullptr) return l1;

            ListNode *head = l1, *tail = head;
            int count = 0;

            ListNode *p1 = l1, *p2 = l2;
            for (; p1 != nullptr && p2 != nullptr; p1 = p1->next, p2 = p2->next) {
                int sum = (p1->val + p2->val + count);
                p1->val = sum % 10;
                count = sum / 10;
                tail = p1;
            }

            if (p2 != nullptr) {
                tail->next = p2;
                for (; p2 != nullptr; p2 = p2->next) {
                    int sum = p2->val + count;
                    p2->val = sum % 10;
                    count = sum / 10;
                    tail = p2;
                }
            } else if (p1 != nullptr){
                tail->next = p1;
                for (; p1 != nullptr; p1 = p1->next) {
                    int sum = p1->val + count;
                    p1->val = sum % 10;
                    count = sum / 10;
                    tail = p1;
                }
            }

            if (count != 0) {
                l2->val = count;
                l2->next = nullptr;
                tail->next = l2;
            }
            return head;
        }
    };
}

#endif //LEETCODE_2_ADD_TWO_NUMBERS_H
