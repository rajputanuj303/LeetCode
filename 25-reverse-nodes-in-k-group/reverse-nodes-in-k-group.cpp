class Solution {
public:
    ListNode* reverse(ListNode* p1, ListNode* p2){
        ListNode* prev = nullptr;
        ListNode* curr = p1;
        ListNode* next = nullptr;

        while(curr != p2){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head) return nullptr;

        ListNode* p1 = head;
        ListNode* p2 = head;

        int count = k; 

        while(count && p2){
            count--;
            p2 = p2->next;
        }

        if(count > 0) return p1;  

        ListNode* nextNode = reverseKGroup(p2, k);
        ListNode* rev1 = reverse(p1, p2);

        p1->next = nextNode;

        return rev1;
    }
};