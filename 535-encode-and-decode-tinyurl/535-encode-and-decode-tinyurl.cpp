class Solution {
public:
    
    // https://leetcode.com/problems/encode-and-decode-tinyurl/discuss/1110674/Encode-and-Decode-TinyURL-or-Short-and-Easy-w-explanation
    
    // string large, small ;
    
    unordered_map<string, string> long_to_short;
    unordered_map<string, string> short_to_long;
    
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
       
        string prefix = "http://tinyurl.com/";
        
        if(long_to_short.find(longUrl) != long_to_short.end())
             return long_to_short[longUrl];
        
        
        string code = "";
        
        string alphanumeric = "abcdefghijklmnopqrstuvwxyzAbCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
        srand(time(0));
        
        while(1)
        {
            for(int i=0; i<7; i++)
               code = code + alphanumeric[rand() % 62];
            
            if(short_to_long.find(prefix + code) == short_to_long.end())
                break;
            
            
            // if(long_to_short.find(code) == long_to_short.end()) // code is not available
                
            code  = "";
                
        }
        
        // string short_url = prefix + code;
        
        long_to_short[longUrl] = prefix + code;
        short_to_long[prefix + code] = longUrl;
        
        return prefix + code;
        
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
       
       // string code = shortUrl.substr(19);
       return short_to_long[shortUrl];
        
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));