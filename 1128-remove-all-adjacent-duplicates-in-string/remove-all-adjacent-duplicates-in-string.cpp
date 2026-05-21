class Solution {
public:
    string removeDuplicates(string s) {
        
        string res = "";

        for(char c : s){
            if(res == "") res += c;
            else{
                if(res.back() == c) res.pop_back();
                else res += c;
            }
        }
        return res;
    }
};