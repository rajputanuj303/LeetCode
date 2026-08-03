class Solution {
public:


    int numMatchingSubseq(string s, vector<string>& words) {
        vector<vector<int>> indexes(26);
        for(int i = 0; i<s.size(); i++){
            indexes[s[i]-'a'].push_back(i);
        }

        int count = 0;

        for(string word : words){

            int prevIdx = -1;
            bool flag = true;

            for(int i = 0; i<word.size(); i++){
                char c = word[i];
                auto it = upper_bound(indexes[c-'a'].begin(), indexes[c-'a'].end(), prevIdx);

                if(it == indexes[c-'a'].end()){
                    flag = false;
                    break;
                }
                prevIdx = *it;
            }

            if(flag) count++;
        }

        return count;
    }
};