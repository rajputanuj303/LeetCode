class Solution {
public:
    vector<char> parents;

    char find(char x){

        if(parents[int(x-'a')] == x) return x;

        return parents[int(x-'a')] = find(parents[int(x-'a')]);
    }

    void unite(char a, char b){

        char pa = find(a);
        char pb = find(b);

        if(pa == pb) return;

        parents[int(pb-'a')] = pa;
    }
    
    bool equationsPossible(vector<string>& equations) {

        for(char c = 'a'; c<='z'; c++){
            parents.push_back(c);
        }

        for(string &s : equations){
            if(s[1] == '='){
                unite(s.front(), s.back());
            }                      
        }  
        for(string &s : equations){
            if(s[1] == '!'){
                char pa = find(s.front());
                char pb = find(s.back());

                if(pa == pb) return false;
            }                      
        }                 
        return true;
    }
};