class Solution {
public:
    int n;
    vector<int> freq;
    string res;
    char oddChar;

    bool Solver(int i, string& curr, const string& target, bool greater) {

        // We have constructed the first half
        if (i == n / 2) {

            // Build the complete palindrome
            string pal = curr;

            if (n % 2 == 1) pal += oddChar;

            string rev = curr;
            reverse(rev.begin(), rev.end());
            pal += rev;

            // Check the COMPLETE palindrome
            if (pal > target) {
                res = pal;
                return true;
            }

            return false;
        }

        for (char c = 'a'; c <= 'z'; c++) {

            if (freq[c - 'a'] == 0) continue;

            // If prefix is still equal to target,
            // we cannot choose a smaller character.
            if (!greater && c < target[i]) continue;

            freq[c - 'a']--;
            curr.push_back(c);

            bool isGreater = greater || (c > target[i]);

            if (Solver(i + 1, curr, target, isGreater))
                return true;

            curr.pop_back();
            freq[c - 'a']++;
        }

        return false;
    }

    string lexPalindromicPermutation(string s, string target) {

        n = s.size();

        // Reset everything
        freq.assign(26, 0);
        res.clear();
        oddChar = '*';

        for (char c : s) freq[c - 'a']++;

        // Check odd frequencies
        int countOdd = 0;

        for (int i = 0; i < 26; i++) {

            if (freq[i] & 1) {
                countOdd++;
                oddChar = char('a' + i);
            }
            if (countOdd > 1) return "";
            // Only half of each character is needed
            freq[i] /= 2;
        }

        string curr = "";

        if (Solver(0, curr, target, false)) return res;
        return "";
    }
};