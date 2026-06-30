class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.length();
        vector<int> count(3, 0); // Count array for 'a', 'b', 'c'
        int left = 0, right = 0, result = 0;

        while (right < n) {
            // Expand the window by including the current character
            count[s[right] - 'a']++;

            // Contract the window as long as it contains all 'a', 'b', 'c'
            while (count[0] > 0 && count[1] > 0 && count[2] > 0) {
                result += n - right; // Add all substrings ending with the current right pointer
                count[s[left] - 'a']--;
                left++; // Shrink the window from the left
            }

            right++;
        }

        return result;
        
    }
};