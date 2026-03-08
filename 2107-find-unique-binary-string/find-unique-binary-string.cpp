class Solution {
public:

    string toBinary(int n, int size){

        string s = "";     
        while(n > 0){
            s = char('0' + (n % 2)) + s;
            n /= 2;
        }

        while(s.size() < size) s = '0' + s;

        return s;
    }

    string generateBits(int n, set<string> &stt){

        for(int i = 0; i<pow(2, n); i++){
            string s = toBinary(i, n);
            if(stt.find(s) == stt.end()) return s;
        }
        return "";
    }

    string findDifferentBinaryString(vector<string>& nums) {
        set<string> stt(nums.begin(), nums.end());

        int n = nums[0].size();
        vector<string> bits;

        return generateBits(n, stt);
    }
};