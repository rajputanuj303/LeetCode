class Solution {
public:
    int n;
    vector<int> freq;
    string res;
    bool Solver(int i, string curr, string target, bool greater){
        if(i == n){
            if(greater){
                res = curr;
                return true;
            }
            return false;
        }

        for(char c = 'a'; c <= 'z'; c++){

            if(freq[c-'a'] == 0) continue;
            if(!greater && c < target[i]) continue;

            curr.push_back(c);
            freq[c - 'a']--;

            bool isGreater = greater || (c > target[i]);

            if(Solver(i+1, curr, target, isGreater)) return true;

            curr.pop_back();
            freq[c-'a']++;
        }

        return false;
    }
    string lexGreaterPermutation(string s, string target) {
        
        n = s.size();
        freq.resize(26, 0);
        for(char c : s){
            freq[c-'a']++;
        }

        bool found = Solver(0, "", target, 0);
        if(found) return res;
        return "";
    }
};