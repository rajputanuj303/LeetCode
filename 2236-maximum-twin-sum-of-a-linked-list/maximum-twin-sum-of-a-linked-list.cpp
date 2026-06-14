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
    int pairSum(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        // cout << slow->val << endl;

        ListNode* curr = head;
        ListNode* prev = nullptr;
        ListNode* next = nullptr;

        while(curr != slow){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        head->next = slow;
        head = prev;


        int maxi = 0;

        while(slow){
            maxi = max(maxi, head->val + slow->val);
            head = head->next;
            slow = slow->next;
        }

        return maxi;
    }
};