class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {

        if(rows == 1) return encodedText;

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

        while (!res.empty() && res.back() == ' ') {
            res.pop_back();
        }

        return res;
    }
};