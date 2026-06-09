class Solution {
public:
    pair<int, int> parse(string s){

        int plusPos = s.find('+');

        int real = stoi(s.substr(0, plusPos));
        int imag = stoi(s.substr(plusPos + 1, s.size() - plusPos - 2));

        return {real, imag};
    }
    string complexNumberMultiply(string num1, string num2) {

        
        auto [a, b] = parse(num1);
        auto [c, d] = parse(num2);

        // cout << a << " " << b << endl;
        // cout << c << " " << d << endl;

        int r1 = (a*c - b*d);
        int r2 = (a*d + b*c);

        string res = to_string(r1) + "+" + to_string(r2) + "i";
        return res;
    }
};