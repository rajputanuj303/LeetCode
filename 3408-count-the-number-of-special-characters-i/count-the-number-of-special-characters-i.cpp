class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_set<char> lower;
        unordered_set<char> upper;

        for(char c : word){
            if(isupper(c)) upper.insert(c);
            else lower.insert(c);
        }

        int count = 0;

        for(char c : lower){
            char u = c - 'a' + 'A';
            if(upper.count(u)) count++;
        }
        return count;
    }
};