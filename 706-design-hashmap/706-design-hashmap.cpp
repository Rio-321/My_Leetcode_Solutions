class MyHashMap {
public:
    
    list<pair<int, int>>* mp;
    int siz;
 
    MyHashMap() {
    
        siz = 1000;
        mp = new list<pair<int,int>>[siz];
    }
    
    
    int Hash(int key)
    {
        return key%siz;
    }
    
 
    void put(int key, int value) {
       
        int ind = Hash(key);
        
        for(auto &x: mp[ind])
        {
            if(x.first == key)
            {
                x.second = value;
                return;
            }
        }
        
        mp[ind].push_back({key, value});
    }
    
    int get(int key) {
        
        int ind = Hash(key);
        for(auto &x: mp[ind])
        {
            if(x.first == key)
                return x.second;
        }
        
        return -1;
    }
    
    void remove(int key) {
        
        int ind = Hash(key);
        for(auto &x: mp[ind])
        {
           if(x.first == key)
           {
               mp[ind].remove({key, x.second});
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