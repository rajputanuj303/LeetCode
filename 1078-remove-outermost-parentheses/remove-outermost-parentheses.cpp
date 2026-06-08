class Solution {
public:
    string removeOuterParentheses(string s) {
        string res;
        int op = 0;

        for(char c : s){
            if(c == '('){
                op++;
                if(op > 1){
                    res += c;
                }
            }else{
                op--;
                if(op > 0) res += c;
            }
        }
        return res;
    }
};