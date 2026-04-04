class Solution {
public:
    void generate(int op, int cl, int &n, vector<string> &result, string &temp){
        if(op > n || cl > op) return;
        if(op == n && cl == n){
            result.push_back(temp);
            return;
        }
        temp += '(';
        generate(op+1, cl, n, result, temp);
        temp.pop_back();
        temp += ')';
        generate(op, cl+1, n, result, temp);
        temp.pop_back();
    }
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string temp = "";
        generate(0, 0, n, result, temp);
        return result;
    }
};


