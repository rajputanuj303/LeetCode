class Solution {
public:
    long long sumAndMultiply(int n) {
        string N = to_string(n);
        string X = "0";
        long long sum = 0;
        for(char c : N){
            if(c != '0'){
                X += c;
                sum += (c - '0');
            }
        }

        return (long long)sum * stoi(X);
    }
};