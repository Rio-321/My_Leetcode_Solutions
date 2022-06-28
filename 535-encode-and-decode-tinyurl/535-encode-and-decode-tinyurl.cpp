class Solution {
public:
    string large, small ;
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        large = longUrl;
        
        // cout<<large[5]<<"\n";
        return large;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        small = shortUrl;
        
        return small;
        
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));