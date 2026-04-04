class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int size = encodedText.size();
        int cols = size/rows;

        string res;

        for(int i = 0; i<cols; i++){
            
            int st = i;

            while(st < size){
                res += encodedText[st];
                st = st + cols + 1;
            }

        }

        int lastdig = res.size()-1;

        while(lastdig >= 0 && res[lastdig] == ' ') lastdig--;

        res.erase(res.begin()+lastdig+1, res.end());

        return res;
    }
};