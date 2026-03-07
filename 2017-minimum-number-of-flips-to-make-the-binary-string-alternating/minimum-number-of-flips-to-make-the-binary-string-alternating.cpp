class Solution {
public:

    void makeAlternating(string& s0, string& s1, int n){

        int prev0 = 1, prev1 = 1;

        for(int i = 0; i<n; i++){
            (prev0) ? s1 += '1' : s1 += '0';
            (prev1) ? s0 += '0' : s0 += '1';

            prev0 = !prev0;
            prev1 = !prev1;
        }
    }

    int minFlips(string s) {

        int n = s.size();

        string winstr = s + s;
        string s0, s1;

        makeAlternating(s0, s1, 2*n);

        int currDiff0 = 0;
        int currDiff1 = 0;

        for(int i = 0; i<n; i++){
            if(winstr[i] != s0[i]) currDiff0++;
            if(winstr[i] != s1[i]) currDiff1++;
        }

        int totalMini = min(currDiff0, currDiff1);

        for(int i = n; i<2*n; i++){

            if(winstr[i] != s0[i]) currDiff0++;
            if(winstr[i-n] != s0[i-n]) currDiff0--;

            if(winstr[i] != s1[i]) currDiff1++;  
            if(winstr[i-n] != s1[i-n]) currDiff1--;        

            // cout << totalMini << " " << currDiff0 << " " << currDiff1 << endl;             

            totalMini = min({totalMini, currDiff0, currDiff1});

        }


        return totalMini;
    }
};