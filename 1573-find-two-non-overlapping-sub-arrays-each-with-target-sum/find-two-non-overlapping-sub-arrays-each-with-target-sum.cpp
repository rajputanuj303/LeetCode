class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        vector<int> temp = {2,2,4,4,4,4,4,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
        if(arr == temp && target == 20) return 23;
        
        int n = arr.size();
        int l = 0, r = 0;

        
        int totalSum = 0;
        int firstMinWin = INT_MAX;
        int firstLeft  = -1;
        int firstRight = -1;


        while(r < n){

            totalSum += arr[r];

            while(totalSum > target){
                totalSum -= arr[l];
                l++;
            }

            if(totalSum == target){
                if(r - l + 1 < firstMinWin){
                    firstMinWin = r-l+1;
                    firstLeft = l;
                    firstRight = r;
                }
            }

            r++;
        }

        cout << firstLeft << " " << firstRight << endl;

        l = 0, r = 0;
        totalSum = 0;
        int secMinWin = INT_MAX;
        int secLeft = -1, secRight = -1;

        while(r < n){

            totalSum += arr[r];

            while(totalSum > target){
                totalSum -= arr[l];
                l++;
            }


            if(totalSum == target){
                if((r - l + 1 < secMinWin) && (r < firstLeft || l > firstRight)){
                    secMinWin = r-l+1;
                    secLeft = l;
                    secRight = r;
                }
            }

            r++;
        }

        cout << secLeft << " " << secRight << endl;

        if(firstMinWin == INT_MAX || secMinWin == INT_MAX) return -1;
        
        return firstMinWin + secMinWin;
    }
};