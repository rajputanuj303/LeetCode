class Solution {
public:
    bool Solver(int i, int j, int aSum, int bSum, bool at, vector<int> &piles){
        if(i > j){
            return (aSum > bSum);
        }


        if(at){

            return Solver(i+1, j, aSum + piles[i], bSum, !at, piles) ||
                   Solver(i, j-1, aSum + piles[j], bSum, !at, piles);

        }else{

            return Solver(i+1, j, aSum, bSum + piles[i], !at, piles) ||
                   Solver(i, j-1, aSum, bSum + piles[j], !at, piles);

        }

    }
    bool stoneGame(vector<int>& piles) {
        return Solver(0, 0, 0, 0, 1, piles);
    }
};