class Solution {
public:
    pair<int, int> parse(string s){

        int n = s.size();
        int i = 0;

        int a = 0;
        bool neg = false;

        if(s[i] =='-'){
            neg = true;
            i++;
        }

        while(i < n && s[i] != '+'){
            a = a*10 + (s[i] - '0');
            i++;
        }
        i++;

        if(neg) a = a*(-1);

        int b = 0;
        neg = false;

        if(s[i] == '-'){
            neg = true;
            i++;
        }

        while(i < n && s[i] != 'i'){
            b = b*10 + (s[i] - '0');
            i++;
        }

        if(neg) b = b*(-1);

        return {a, b};
    }
    string complexNumberMultiply(string num1, string num2) {

        
        auto [a, b] = parse(num1);
        auto [c, d] = parse(num2);

        // cout << a << " " << b << endl;
        // cout << c << " " << d << endl;

        int r1 = (a*c) - (b*d);
        int r2 = (a*d + b*c);

        string res = to_string(r1) + "+" + to_string(r2) + "i";
        return res;
    }
};