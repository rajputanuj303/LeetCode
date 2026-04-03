class Solution {
public:
    
    string reorganizeString(string s) {

        vector<int> freq(26, 0);

        int n = s.size();

        for(char c : s){
            freq[c-'a']++;
            if(freq[c-'a'] > (n+1)/2) return "";
        }

        priority_queue<pair<int, char>> pq;

        for(int i = 0; i<26; i++){
            if(freq[i] > 0){
                pq.push({freq[i], 'a'+i});
            }
        }

        // cout << pq.top().second << " " << pq.top().first << endl;

        string res;

        while(!pq.empty()){

            pair<int, char> temp1 = pq.top(); pq.pop();
            
            if(!res.empty() && res.back() == temp1.second){
                pair<int, char> temp2 = pq.top(); pq.pop();
                res += temp2.second;
                if(temp2.first - 1 > 0){
                    pq.push({temp2.first-1, temp2.second});
                }
                pq.push(temp1);
            }else{
                res += temp1.second;
                if(temp1.first-1 > 0){
                    pq.push({temp1.first-1, temp1.second});
                }
            }
        }
        return res;
    }
};