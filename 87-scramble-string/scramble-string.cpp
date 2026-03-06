class Solution {
public:
    unordered_map<string, bool> mpp;

    bool Solver(string s1, string s2){
        if(s1 == s2) return true;
        if(s1.size() != s2.size()) return false;

        string key = s1 + "_" + s2;
        if(mpp.find(key) != mpp.end()) return mpp[key];

        int n = s1.size();
        bool result = false;

        for(int i = 1; i<n; i++){
            string a1 = s1.substr(0, i);
            string a2 = s1.substr(i, n-i);
            string b1 = s2.substr(0, i);
            string b2 = s2.substr(i, n-i);
            bool notSwapped = Solver(a1, b1) && Solver(a2, b2);

            a1 = s1.substr(0, i);
            a2 = s2.substr(n-i, i);
            b1 = s1.substr(i, n-i);
            b2 = s2.substr(0, n-i);
            bool swapped = Solver(a1, a2) && Solver(b1, b2);

            if(swapped || notSwapped){
                result = true;
                break;
            }
        }
        return mpp[key] = result;
    }
    bool isScramble(string s1, string s2) {
        return Solver(s1, s2);        
    }
};