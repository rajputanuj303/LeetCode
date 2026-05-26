class Solution {
public:

    unordered_map<string, int> encodedDB;
    unordered_map<int, string> decodedDB;

    int counter = 0;

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        if(encodedDB.count(longUrl)) return to_string(encodedDB[longUrl]);
        decodedDB[counter] = longUrl;
        encodedDB[longUrl] = counter++;
        return to_string(encodedDB[longUrl]);
    }

    

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        int cntr = stoi(shortUrl);
        return decodedDB[cntr];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));