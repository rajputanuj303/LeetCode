class Solution {
public:
    int minAddToMakeValid(string s) {
        
        int balance = 0;

        int totalCount = 0;

        for(int i = 0; i<s.size(); i++){
            if(s[i] == '('){
                if(balance < 0){
                    totalCount += abs(balance);
                    balance = 1;
                }else{
                    balance++;
                }
            }else{
                balance--;
            }
        }

        totalCount += abs(balance);

        return totalCount;
    }
};