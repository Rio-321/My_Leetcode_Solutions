class TimeMap {
public:
    
    unordered_map<string, vector<pair<int,string>>> mp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        
        mp[key].push_back({timestamp,value});
        
    }
    
    string get(string key, int timestamp) {
           
        if(mp.count(key) == 0)
            return "";
        
        int l = 0;
        int r = mp[key].size()-1;
        int ans = -1;
        
        while(l<=r)
        {
            int mid = l + (r-l)/2;
            
            if(mp[key][mid].first == timestamp)
                return mp[key][mid].second;
            
            if(mp[key][mid].first > timestamp)
            {
                r = mid-1;
            }
            else
            {
                ans = mid;
                l = mid+1;
            }
        }
        
        if(ans != -1)
        return mp[key][ans].second;
        
        return "";
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */