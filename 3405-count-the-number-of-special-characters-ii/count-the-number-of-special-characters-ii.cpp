class Solution {
public:
    int numberOfSpecialChars(string word) {
        int n = word.size();

        vector<int> lastLowerOcc(26, -1);

        for(int i = 0; i<n; i++){
            if(islower(word[i])) lastLowerOcc[word[i] - 'a'] = i;
        }

        int res = 0;

        for(int i = 0; i<n; i++){
            if(isupper(word[i])){
                if(lastLowerOcc[word[i] - 'A'] != -1){

                    if(lastLowerOcc[word[i] - 'A'] < i) res++;
                    lastLowerOcc[word[i] - 'A'] = -1;
                    
                }
            }
        }

        return res;
    }
};