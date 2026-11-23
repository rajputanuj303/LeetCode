/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        ListNode* tempA = headA;
        ListNode* tempB = headB;

        while(tempA != tempB){ 
  
            tempA = (tempA == nullptr) ? headB : tempA = tempA->next;  
            tempB = (tempB == nullptr) ? headA : tempB = tempB->next;  
        }


        return tempA;        
    }
};