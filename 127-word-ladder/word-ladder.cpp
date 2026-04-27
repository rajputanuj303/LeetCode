class Solution {
public:

    unordered_set<string> wordListSet;
    unordered_set<string> visited;

    vector<string> hasOneDiff(string &s, vector<string> &oneDiff){

        int n = s.size();

        for(char c = 'a'; c<='z'; c++){
            for(int i = 0; i<n; i++){
                char temp = s[i];
                s[i] = c;
                
                if(!visited.count(s) && wordListSet.count(s)){
                    oneDiff.push_back(s);
                    visited.insert(s);
                }
                s[i] = temp;
            }
        }

        return oneDiff;
    }


    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        for(string &s : wordList) wordListSet.insert(s);

        if(!wordListSet.count(endWord)) return 0;

        queue<string> que;

        que.push(beginWord);
        
        visited.insert(beginWord);

        int pathLen = 1;

        while(!que.empty()){

            int size = que.size();

            vector<string> oneDiff;

            for(int i = 0; i<size; i++){                
                string currWord = que.front();
                que.pop();

                if(currWord == endWord) return pathLen;
                
                hasOneDiff(currWord, oneDiff);                
            }

            for(string &s : oneDiff) que.push(s);

            pathLen++;                       
        }
        return 0;
    }
};