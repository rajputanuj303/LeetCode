class Solution {
public:
    int maxDepth(string s) {
        
        int maxDepth = 0;
        int currOpen = 0;

        for(char &c : s){
            if(c == '(') currOpen++;
            else if(c == ')'){
                maxDepth = max(maxDepth, currOpen);
                currOpen--;
            }
        }

        return maxDepth;
    }
};