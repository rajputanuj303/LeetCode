class Solution {
public:

    string Solver(int &i, int n, string &s) {
        string temp = "";

        while (i < n) {

            if (s[i] == '(') {
                i++;
                string inside = Solver(i, n, s);
                reverse(inside.begin(), inside.end());
                temp += inside;
            }
            else if (s[i] == ')') {
                i++;
                return temp;
            }
            else {
                temp += s[i];
                i++;
            }
        }

        return temp;
    }

    string reverseParentheses(string s) {
        int i = 0;
        return Solver(i, s.size(), s);
    }
};

