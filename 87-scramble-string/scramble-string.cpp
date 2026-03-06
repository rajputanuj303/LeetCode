class Solution {
public:
    unordered_map<string, bool> mpp;

    bool Solver(string s1, string s2){
        if(s1 == s2) return true;
        if(s1.size() != s2.size()) return false;

        string key = s1 + "_" + s2;
        if(mpp.count(key)) return mpp[key];

        int n = s1.size();
        bool result = false;

        for(int i = 1; i<n; i++){

            bool notSwapped = Solver(s1.substr(0, i), s2.substr(0, i)) && 
                            Solver(s1.substr(i, n-i), s2.substr(i, n-i));

            bool swapped = Solver(s1.substr(0, i), s2.substr(n-i, i)) && 
                           Solver(s1.substr(i, n-i), s2.substr(0, n-i));

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