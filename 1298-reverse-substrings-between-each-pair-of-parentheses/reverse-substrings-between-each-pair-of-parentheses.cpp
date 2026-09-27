class Solution {
public:
    string reverseParentheses(string s) {

        stack<string> st;
        string curr = "";

        for(char ch : s) {

            if(ch == '(') {
                // Save current string
                st.push(curr);
                curr = "";
            }
            else if(ch == ')') {
                // Reverse content inside ()
                reverse(curr.begin(), curr.end());

                // Append it to the previous level
                curr = st.top() + curr;
                st.pop();
            }
            else {
                curr += ch;
            }
        }

        return curr;
    }
};