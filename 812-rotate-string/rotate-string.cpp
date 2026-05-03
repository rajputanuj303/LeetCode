class Solution {
public:
    bool rotateString(string s, string goal) {
        for(int i = 0; i<s.size(); i++){
            string temp(s.begin()+i, s.end());
            temp.insert(temp.end(), s.begin(), s.begin()+i);
            if(temp == goal) return true;
        } 
        return false;
    }
};