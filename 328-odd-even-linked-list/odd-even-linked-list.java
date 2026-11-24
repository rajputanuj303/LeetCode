/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) {
 *         this.val = val;
 *         this.next = next;
 *     }
 * }
 */

class Solution {
    public ListNode oddEvenList(ListNode head) {
        if (head == null || head.next == null) return head;

        boolean evenIndex = true;

        ListNode ptr1 = head;
        ListNode ptr2 = head.next;
        ListNode initialPtr2 = ptr2;

        ListNode temp = head.next.next;

        while (temp != null) {
            if (evenIndex) {
                ptr1.next = temp;
                ptr1 = ptr1.next;
            } else {
                ptr2.next = temp;
                ptr2 = ptr2.next;
            }

            evenIndex = !evenIndex;
            temp = temp.next;
        }

        ptr1.next = initialPtr2;
        ptr2.next = null;

        return head;
    }
}