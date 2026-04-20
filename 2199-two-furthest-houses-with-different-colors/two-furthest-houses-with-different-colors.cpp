class Solution {
public:
    int maxDistance(vector<int>& colors) {
        

        int i = 0, j = colors.size()-1;

        int maxSize = 0;


        if(colors[i] == colors[j]){
            int x = j-1;
            while(x >= i && colors[x] == colors[j]) x--;

            maxSize = max(maxSize, x-i);

            x = i+1;
            while(x < j && colors[x] == colors[i]) x++;
            maxSize = max(maxSize, j-x);
        }else return j-i;

        return maxSize;
    }
};