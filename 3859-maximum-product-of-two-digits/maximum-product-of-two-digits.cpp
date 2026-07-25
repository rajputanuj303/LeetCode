class Solution {
public:
    int maxProduct(int n) {
        vector<int> temp;
        while(n){
            temp.push_back(n%10);
            n/=10;
        }
        int mul = INT_MIN;
        for(int i = 0; i<temp.size(); i++){
            for(int j = i+1; j<temp.size(); j++){
                mul = max(mul, temp[i]*temp[j]);
            }
        }
        return mul;
    }
};