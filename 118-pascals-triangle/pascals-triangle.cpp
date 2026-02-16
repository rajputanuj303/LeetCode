class Solution {
public:

    int nCr(int n, int r){
        if(r > n) return 0;
        if(n == r || r == 0) return 1;


        return (n*nCr(n-1, r))/(n-r);
    }
    vector<vector<int>> generate(int n) {
        

        vector<vector<int>> res;


        for(int i = 0; i<n; i++){
            vector<int> temp;
            for(int j = 0; j<=i; j++){
                int val = nCr(i, j);
                temp.push_back(val);
            }
            res.push_back(temp);
        }
        return res;
    }
};