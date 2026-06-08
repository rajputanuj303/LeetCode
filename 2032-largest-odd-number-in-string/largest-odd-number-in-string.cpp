class Solution {
public:
    bool iseven(char c){
        if(c == '2' || c == '4' || c == '6' || c == '8' || c == '0') return true;
        return false;
    }
    string largestOddNumber(string num) {
        
        int n = num.size();
        int i = n-1;

        while(i >= 0 && iseven(num[i])) i--; 

        return num.substr(0, i+1);
    }
};