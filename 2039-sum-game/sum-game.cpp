class Solution {
public:
    bool sumGame(string num) {
        
        int n = num.size();
        int leftSum = 0;
        int rightSum = 0;
        int leftBlank = 0;
        int rightBlank = 0;

        for(int i = 0; i < n; i++){
            if(i < n/2){
                if(num[i] == '?') leftBlank++;
                else leftSum += (num[i] - '0');
            }else{
                if(num[i] == '?') rightBlank++;
                else rightSum += (num[i] - '0');
            }
        }

        // TotalBlank == odd then Alice Wins
        if((leftBlank + rightBlank) % 2 == 1) return true;

        // Equal number of blanks
        if(leftBlank == rightBlank){
            return leftSum != rightSum;
        }

        int remSum = leftSum - rightSum;
        int remBlank = leftBlank - rightBlank;

        // Left has more blanks
        if(remBlank > 0){
            // Bob can control remBlank / 2 blanks on the left.
            // For Bob to win, left needs to be behind by exactly this amount.
            int BobGets = remBlank / 2;

            return remSum != -9 * BobGets;
        }

        // Right has more blanks
        else {
            // Bob can control -remBlank / 2 blanks on the right.
            // For Bob to win, right needs to be behind by exactly this amount.
            int BobGets = (-remBlank) / 2;

            return remSum != 9 * BobGets;
        }
    }
};
