class MyHashSet {
public:

    int* set;
    int siz;
    MyHashSet() {
        siz = 1e6+1;
         set = new int[siz];
        for(int i=0;i<siz;i++)
            set[i] = 0;
    }
    
    void add(int key) {
        
        set[key] = 1;
    }
    
    void remove(int key) {
        
        set[key] = 0;
    }
    
    bool contains(int key) {
        if(set[key])
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