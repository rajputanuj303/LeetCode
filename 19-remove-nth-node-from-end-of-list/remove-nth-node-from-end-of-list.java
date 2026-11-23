
class Solution {
    public ListNode removeNthFromEnd(ListNode head, int n) {

        int len = 0;

        ListNode temp = head;

        while (temp != null) {
            len++;
            temp = temp.next;
        }

        int deletepos = len - n;

        // If head needs to be deleted
        if (deletepos == 0) {
            return head.next;
        }

        temp = head;
        int i = 0;

        while (i != deletepos - 1) {
            temp = temp.next;
            i++;
        }

        temp.next = temp.next.next;


        return head;
    }
}
