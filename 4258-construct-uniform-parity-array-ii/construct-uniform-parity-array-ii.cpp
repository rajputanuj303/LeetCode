class Solution {
public:
    bool uniformArray(vector<int>& nums1) {

        bool alleven = true;
        bool allodd = true;
        
        int minVal = INT_MAX;

        for(int i = 0; i<nums1.size(); i++){
            if(nums1[i]%2 == 0){
                allodd =  false;
            }else{
                alleven = false;
            }
            minVal = min(minVal, nums1[i]);
        }

        if(alleven || allodd) return true;
        
        if(minVal%2 != 0) return true;

        return false;
    }
};