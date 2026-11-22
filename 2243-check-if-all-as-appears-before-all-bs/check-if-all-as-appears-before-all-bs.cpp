class Solution {
public:
    bool checkString(string s) {
        
        int n = s.size();

        int lastA = -1;
        int firstB = n;

        for(int i = 0; i<n; i++){
            if(s[i] == 'a') lastA = i;
            if(s[n-i-1] == 'b') firstB = n-i-1;
        }

        return lastA < firstB;
    }
};