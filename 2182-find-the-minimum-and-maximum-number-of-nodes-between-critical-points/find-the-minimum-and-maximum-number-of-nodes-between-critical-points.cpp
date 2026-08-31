class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if (!head || !head->next || !head->next->next)
            return {-1, -1};

        int first = -1;       // First critical point
        int last = -1;        // Previous critical point
        int minDist = INT_MAX;

        ListNode* prev = head;
        ListNode* curr = head->next;

        int idx = 1;

        while (curr->next) {
            int val = curr->val;

            // Check whether curr is a critical point
            if ((val > prev->val && val > curr->next->val) ||
                (val < prev->val && val < curr->next->val)) {

                if (first == -1) {
                    // First critical point
                    first = idx;
                } else {
                    // Distance from previous critical point
                    minDist = min(minDist, idx - last);
                }

                last = idx;
            }

            prev = curr;
            curr = curr->next;
            idx++;
        }

        // Fewer than 2 critical points
        if (first == -1 || first == last) return {-1, -1};

        return {minDist, last - first};
    }
};