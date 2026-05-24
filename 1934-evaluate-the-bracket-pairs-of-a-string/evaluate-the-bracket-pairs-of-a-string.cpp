class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> mpp;

        for(vector<string> &v : knowledge){
            mpp[v[0]] = v[1];
        }

        string res = "";

        int i = 0;
        int n = s.size();

        while(i < n){
            if(s[i] == '('){
                i++;
                string temp = "";
                while(i < n && s[i] != ')') temp += s[i++];

                auto it = mpp.find(temp);
                (it == mpp.end()) ? res += "?" : res += it->second;
                
            }else{
                res += s[i];
            }
            i++;
        }
        return res;
    }
};