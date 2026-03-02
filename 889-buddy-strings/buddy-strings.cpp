class Solution {
public:
    bool buddyStrings(string s, string goal) {

        if(s.size() != goal.size()) return false;

        int n = s.size();
        vector<bool> arr(n, false);

        for(int i = 0; i<n; i++){
            if(s[i] == goal[i]) arr[i] = true;
        }

        int idx1 = -1, idx2 = -1;

        for(int i = 0; i<n; i++){
            if(arr[i] == false){
                if(idx1 == -1) idx1 = i;
                else if(idx2 == -1) idx2 = i;
                else return false;
            }
        }

        // cout << idx1 << " " << idx2 << endl;

        if(idx1 == -1 && idx2 == -1){
            vector<int> freq1(26, 0);
            vector<int> freq2(26, 0);

            for(int i = 0; i<n; i++) freq1[s[i]-'a']++;
            for(int i = 0; i<n; i++) freq2[goal[i]-'a']++;

            for(int i = 0; i<26; i++){
                if(freq1[i] >= 2 && freq2[i] >= 2) return true;
            }
            return false;
            
        }

        if(idx1 == -1 || idx2 == -1) return false;
                
        if(s[idx1] == goal[idx2] && s[idx2] == goal[idx1]) return true;
        return false;
    }
};