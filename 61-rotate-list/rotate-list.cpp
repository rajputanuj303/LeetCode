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
    // ListNode* bruteRotate(ListNode* head, int k){

    //     vector<int> arr;
    //     ListNode* temp = head;
    //     while(temp){
    //         arr.push_back(temp->val);
    //         temp = temp->next;
    //     }
        
    //     int n = arr.size();
    //     k = k % n;
    //     vector<int> arr1, arr2;
    //     arr1.insert(arr1.begin(), arr.begin(), arr.end()-k);
    //     arr2.insert(arr2.begin(), arr.end()-k, arr.end());

    //     arr = arr2;
    //     arr.insert(arr.end(), arr1.begin(), arr1.end());
    //     return arr;
    // }
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next || k == 0) return head;

        int n = 1;
        ListNode* end = head;
        while(end->next){
            n++;
            end = end->next;
        }
        end->next = head;

        k = k % n;
        int itr = n-k;
        ListNode* tail = end;
        while(itr--){
            tail = tail->next;
        }
        
        head = tail->next;
        tail->next = nullptr;
        
        return head;    
    }
};