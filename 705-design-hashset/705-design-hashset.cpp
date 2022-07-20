class MyHashSet {
public:

    int* set;
    
    MyHashSet() {
         set = new int[1000001];
        for(int i=0;i<1000001;i++)
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