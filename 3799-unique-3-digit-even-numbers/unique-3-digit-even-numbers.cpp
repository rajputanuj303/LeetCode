class Solution {
public:
    int totalNumbers(vector<int>& digits) {

        int freq[10] = {};
        for (int d : digits) freq[d]++;

        int count = 0;

        for (int i = 1; i <= 9; i++) {

            if (!freq[i]) continue;
            freq[i]--;

            for (int j = 0; j <= 9; j++) {

                if (!freq[j]) continue;
                freq[j]--;

                for (int k = 0; k <= 8; k += 2) {
                    if (freq[k]) count++;
                }

                freq[j]++;
            }

            freq[i]++;
        }

        return count;
    }
};