class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {

        ListNode sum = new ListNode();
        ListNode dummy = sum;

        int carry = 0;

        while (l1 != null || l2 != null) {

            int digitSum = carry;

            if (l1 != null) {
                digitSum += l1.val;
                l1 = l1.next;
            }

            if (l2 != null) {
                digitSum += l2.val;
                l2 = l2.next;
            }   


            dummy.next = new ListNode(digitSum % 10);
            dummy = dummy.next;
            carry = digitSum / 10;
        }

        if (carry > 0) {
            dummy.next = new ListNode(carry);
        }

        return sum.next;
    }
}