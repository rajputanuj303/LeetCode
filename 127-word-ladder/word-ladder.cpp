class Solution {
public:

    unordered_set<string> wordListSet;
    unordered_set<string> visited;

    vector<string> hasOneDiff(string s){

        vector<string> oneDiff;
        int n = s.size();

        for(char c = 'a'; c<='z'; c++){
            for(int i = 0; i<n; i++){
                char temp = s[i];
                s[i] = c;

                if(!visited.count(s) && wordListSet.count(s)){
                    oneDiff.push_back(s);
                }              

                s[i] = temp;
            }
        }

        return oneDiff;
    }


    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        for(string s : wordList) wordListSet.insert(s);

        if(!wordListSet.count(endWord)) return 0;

        queue<pair<string, int>> que;

        que.push({beginWord, 1});
        
        visited.insert(beginWord);

        while(!que.empty()){

            string currWord = que.front().first;
            int pathLen = que.front().second;
            que.pop();

            if(currWord == endWord) return pathLen;

            vector<string> oneDiff = hasOneDiff(currWord);

            for(string s : oneDiff){
                visited.insert(s);
                que.push({s, pathLen+1});
            }            
        }
        return 0;
    }
};