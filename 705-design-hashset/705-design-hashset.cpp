class MyHashSet {
public:

    list<int>* st;
    int siz;
    
    MyHashSet() {
        siz = 1000;
        st = new list<int>[siz];
    }
    
    int hash(int key)
    {
        return key % siz;
    }
    
    void add(int key) {
        
        if(contains(key)) return;
        
        int i = hash(key);
        
        st[i].push_back(key);   
       
    }
    
    void remove(int key) {
        
        int i = hash(key);
        st[i].remove(key);
        
    }
    
    bool contains(int key) {
      
        int i = hash(key);
        for(auto x: st[i])
            if(x == key)
                return true;
        
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */