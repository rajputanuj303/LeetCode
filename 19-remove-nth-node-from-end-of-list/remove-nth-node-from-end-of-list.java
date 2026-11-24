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
    public int findLen(ListNode head){

        int counter = 0;

        while(head != null){
            counter++;
            head = head.next;
        }

        return counter;
    }
    public ListNode removeNthFromEnd(ListNode head, int n) {
        

        int len = findLen(head);  // find Length of LL.

        if(n == len) return head.next;

        int frontIdx = len - n;
        int idx = 0;

        ListNode prev = null;
        ListNode curr = head;

        while(idx != frontIdx){
            idx++;

            prev = curr;
            curr = curr.next;
        }

        if(curr != null) prev.next = curr.next;

        return head;

    }
}