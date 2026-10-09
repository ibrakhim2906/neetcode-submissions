/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */

class Solution {
    public ListNode mergeTwoLists(ListNode list1, ListNode list2) {
        ListNode dummy = new ListNode(0);
        ListNode tail = dummy;

        ListNode ls1 = list1;
        ListNode ls2 = list2;
        
        while (ls1!=null && ls2!=null) {
            if (ls1.val<ls2.val) {
                tail.next=ls1;
                ls1=ls1.next;
            } else {
                tail.next=ls2;
                ls2=ls2.next;
            }
            tail=tail.next;
        }

        if (ls1!=null) {
            tail.next=ls1;
        }

        else {
            tail.next=ls2;
        }

        return dummy.next;
    }
}