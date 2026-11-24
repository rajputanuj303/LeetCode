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
    ListNode* mergeTwoLists(ListNode* h1, ListNode* h2) {
       
       if(h1==NULL || h2==NULL){
        return h1==NULL ? h2 : h1;
       }

       if(h1->val <= h2->val){
        h1->next=mergeTwoLists(h1->next,h2);
        return h1;
       }
       else{
        h2->next=mergeTwoLists(h1,h2->next);
        return h2;
       }
       
    }
};