class Solution {
public:
    int reverseDegree(string s) {
        


        int sum = 0;

        for(int i = 0; i<s.size(); i++){
            // cout << c - 'a' << endl;
            sum += (i+1)*(26 - (s[i] - 'a'));
        }

        return sum;
    }
};