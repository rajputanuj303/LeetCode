class Solution {
public:
    void AddOne(string &s) {
        int i = s.size() - 1;

        while (i >= 0 && s[i] == '1') {
            s[i] = '0';
            i--;
        }

        if (i >= 0) {
            s[i] = '1';
        } else {
            s.insert(s.begin(), '1');
        }

        cout << s << endl;
    }
    int numSteps(string s) {

        int count = 0;
        int n = s.size();

        while(true){

            if(s == "1") break;

            if(s[n-1] == '1'){
                AddOne(s);
            }
            else{
                s.pop_back();
            }

            count++;
            n = s.size();
        }

        return count;
    }
};