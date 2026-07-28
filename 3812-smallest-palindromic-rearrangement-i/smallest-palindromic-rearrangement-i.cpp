class Solution {
public:
    string smallestPalindrome(string s) {

        vector<int> freq(26, 0);
        for(char c : s) freq[c-'a']++;
        
        string forward;
        char ex = '*';

        for(int i = 0; i<26; i++){
            int f = freq[i];            
            if(f&1) ex = 'a' + i;
            forward  += string(f/2, 'a' + i);
        }

        string pal = forward;

        if(ex != '*') pal += ex;

        reverse(forward.begin(), forward.end());
        pal = pal + forward;

        return pal;
    }
};