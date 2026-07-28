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
            
            if(f&1){
                ex = 'a'+i;
            }

            int half = f/2;
            while(half--){
                forward  += 'a'+i;
                backward += 'a'+i;
            }
        }

        if(ex != '*') backward += ex;

        reverse(backward.begin(), backward.end());

        return forward + backward;
    }
};