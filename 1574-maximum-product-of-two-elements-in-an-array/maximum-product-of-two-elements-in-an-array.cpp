class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max1 = 0, max2 = 0;
        for(int i : nums){
            if(i > max1){
                max2 = max1;
                max1 = i;
            }else if(i > max2){
                max2 = i;
            }
        }

        cout << max1 << " " << max2 << endl;

        return (max1-1)*(max2-1);
    }
};