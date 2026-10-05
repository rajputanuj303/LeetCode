class Solution {
public:
    int scoreOfParentheses(string s) {

        int n = s.size();

        vector<int> RankScore(n+1, 0);

        int rank = 0;

        for(int i = 0; i<n; i++){
            if(s[i] == '(') rank++;
            else{
                RankScore[rank] += (RankScore[rank+1] == 0 ? 1 : RankScore[rank+1]*2);
                RankScore[rank+1] = 0;
                rank--;
            }
        }
        
        return RankScore[1];        
    }
};