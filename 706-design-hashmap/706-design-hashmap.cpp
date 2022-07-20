class MyHashMap {
public:
    
    list<pair<int,int>>* mp;
    int siz;
    
    MyHashMap() {
        siz = 1000;
        mp = new list<pair<int,int>>[siz]; 
    }
    
    int hash(int key)
    {
        return key % siz;
    }
    
    void put(int key, int value) {
        
        int i = hash(key);
        for(auto &x: mp[i])
        {
            if(key == x.first)
            {
                x.second = value;
                // cout<<x.first<<" "<<x.second<<"\n";
                return;
            }
        }
        
        mp[i].push_back({key, value});
        
    }
    
    int get(int key) {
          
        int i = hash(key);
        for(auto x: mp[i])
        {
            if(key == x.first)
                return x.second;
        }
        
        return -1;
    }
    
    void remove(int key) {
        
        int i = hash(key);
        
        for(auto x:mp[i])
        {
            if(key == x.first)
            {
                mp[i].remove({key, x.second});
                return;
            }
        }
        
        
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */