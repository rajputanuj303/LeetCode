class Solution {
public:
    int numberOfSpecialChars(string word) {
        
        int n = word.size();
        vector<int> lowerFreq(26, 0);
        vector<int> prefixCount(n, 0);


        for(int i = 0; i<n; i++){
            if(islower(word[i])){
                lowerFreq[word[i] - 'a']++;
            }else{
                prefixCount[i] = lowerFreq[word[i] - 'A'];
            }
        }

        int res = 0;

        for(int i = 0; i < n; i++){

            if(isupper(word[i])){
                if(prefixCount[i] == 0 || prefixCount[i] < lowerFreq[word[i] - 'A']){
                    lowerFreq[word[i] - 'A'] = 1e9+7;
                    continue;
                }
                lowerFreq[word[i] - 'A'] = 1e9+7;
                res++;
            }

        }

        return res;
    }
};