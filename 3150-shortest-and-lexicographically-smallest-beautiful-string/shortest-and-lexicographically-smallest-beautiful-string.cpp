class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();

        int left = 0;
        int right = 0;
        int ones = 0;

        string ans = "";

        while(right < n) {

            if (s[right] == '1')
                ones++;

            // Too many ones -> move left
            while (ones > k) {
                if (s[left] == '1')
                    ones--;

                left++;
            }

            // We have exactly k ones
            if (ones == k) {

                // Remove unnecessary leading zeros
                while (left < right && s[left] == '0') {
                    left++;
                }

                string cur = s.substr(left, right - left + 1);

                if (ans == "" || 
                    cur.size() < ans.size() ||
                    (cur.size() == ans.size() && cur < ans)
                ) {
                    ans = cur;
                }
            }

            right++;
        }

        return ans;
    }
};