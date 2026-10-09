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
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        ListNode* first = head;

        int size = 0;
        
        while (first != nullptr)
        {
            first = first->next;
            size++;
        }

        if (size == n)
        {
            return head->next;
        }

        ListNode* second = head;

        for (int i = 0; i < size - n - 1; i++)
        {

            second = second->next;

        }

        second->next = second->next->next;

        return head;
    }

};