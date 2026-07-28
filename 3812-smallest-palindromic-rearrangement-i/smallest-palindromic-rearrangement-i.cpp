class Solution {
public:
    string smallestPalindrome(string s) {

        vector<int> freq(26, 0);

        for(char c : s) freq[c-'a']++;
        
        string forward;
        string backward;

        char ex = '*';

        for(int i = 0; i<26; i++){
            
            int f = freq[i];            
            if(f&1) ex = 'a' + i;

            forward  += string(f/2, 'a' + i);
            backward += string(f/2, 'a' + i);
        }

        if(ex != '*') backward += ex;

        reverse(backward.begin(), backward.end());

        return forward + backward;
    }
};