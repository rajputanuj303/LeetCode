class Solution {
public:

    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
    
        int maxDist = 0;
        int m = nums1.size();
        int n = nums2.size();

        for(int i = 0; i<m; i++){
            
            int low = i, high = n-1;

            int farIdx = -1;

            while(low <= high){

                int mid = low + (high-low)/2;

                if(nums2[mid] >= nums1[i]){
                    farIdx = mid;
                    low = mid+1;
                }else high = mid-1;
            }

            if(farIdx != -1) maxDist = max(maxDist, farIdx - i);
        }

        return maxDist;
    }
};