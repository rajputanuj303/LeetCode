class Solution {
public:
    int passwordStrength(string password) {
        
        bool seen[128] = {false}; // all possible characters
        int res = 0;

        for(char c : password) {
            
            if(seen[c]) continue;
            seen[c] = true; 

            if(c >= 'a' && c <= 'z') {
                res += 1;
            } else if(c >= 'A' && c <= 'Z') {
                res += 2;
            } else if(c >= '0' && c <= '9') {
                res += 3;
            } else if(c == '!' || c == '@' || c == '#' || c == '$') {
                res += 5;
            }
        }
        
        return res;
    }
};