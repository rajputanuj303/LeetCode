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
    bool isSatisfying(ListNode* curr, ListNode* prev, ListNode* next){
        if(curr->val > prev->val && curr->val > next->val) return true;
        else if(curr->val < prev->val && curr->val < next->val) return true;
        return false;
    }
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if(!head || !head->next || !head->next->next) return {-1, -1};
        
        int currIdx = 1;
        int firstIdx = -1;
        int prevIdx = -1;

        ListNode* prev = head;
        ListNode* curr = head->next;

        int minDis = INT_MAX;
        int maxDis = INT_MIN;

        while(curr->next){
            
            if(isSatisfying(curr, prev, curr->next)){

                if(firstIdx == -1){
                    firstIdx = currIdx;
                    prevIdx = currIdx;
                    currIdx++;
                    prev = curr;
                    curr = curr->next;
                    continue;
                }

                minDis = min(minDis, currIdx - prevIdx);
                maxDis = max(maxDis, currIdx - firstIdx);

                prevIdx = currIdx;
            }
            prev = curr;
            curr = curr->next;
            currIdx++;
        }




        if(minDis == INT_MAX) return {-1, -1};
        return {minDis, maxDis};
    }
};