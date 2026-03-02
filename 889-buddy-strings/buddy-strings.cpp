class Solution {
public:
    bool buddyStrings(string s, string goal) {

        if(s.size() != goal.size()) return false;

        int n = s.size();
        vector<int> freq(26, 0);

        int idx1 = -1, idx2 = -1;

        for(int i = 0; i<n; i++){

            if(s[i] != goal[i]){
                if(idx1 == -1) idx1 = i;
                else if(idx2 == -1) idx2 = i;
                else return false;
            }
            freq[s[i]-'a']++;
        }

        // cout << idx1 << " " << idx2 << endl;

        if(idx1 == -1 && idx2 == -1){

            for(int i = 0; i<26; i++){
                if(freq[i] >= 2) return true;
            }
            return false;            
        }

        if(idx1 == -1 || idx2 == -1) return false;
                
        if(s[idx1] == goal[idx2] && s[idx2] == goal[idx1]) return true;

        return false;
    }
};