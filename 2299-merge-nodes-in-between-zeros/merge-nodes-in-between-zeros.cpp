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
    ListNode* mergeNodes(ListNode* head) {
        
        ListNode* p1 = head;
        ListNode* temp = head;

        int val = 0;
        
        while(p1 != nullptr){            
            if(p1->val == 0){
                if(val != 0){
                    temp->next->val = val;
                    temp = temp->next;
                }                    
                val = 0;
                p1 = p1->next;
            }else{
                val += p1->val;
                p1 = p1->next;
            }
        }
        temp->next = nullptr;
        return head->next;

    }
};