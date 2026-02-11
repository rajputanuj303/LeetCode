class Solution {
public:
    bool checkOnesSegment(string s) {
        
        bool prevZero = 0;
        for(int i = 0; i<s.size(); i++){
            if(s[i] == '0') prevZero = 1;
            if(prevZero && s[i] == '1') return false;
        }
        return true;
    }
};