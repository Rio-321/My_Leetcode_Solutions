class LRUCache {
public:

    class Node{
        public:
        
        int key;
        int value;
        Node* prev;
        Node* next;
        
        
        Node(int key, int value)
        {
            this->value = value;
            this->key = key;
            prev = NULL;
            next = NULL;
        }
            
    };
    
    Node* head = new Node(-1,-1);
    Node* tail = new Node(-1,-1);
    
    unordered_map<int, Node*> mp;
    int cap;
   
    LRUCache(int capacity) 
    {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    void changePos(Node* resnode)
    {
             resnode->prev->next = resnode->next;
             resnode->next->prev = resnode->prev;
             
             resnode->next = head->next;
             head->next = resnode;
             resnode->next->prev = resnode;
             resnode->prev = head;
    }
 
    
    int get(int key) 
    {
         if(mp.find(key) != mp.end()) // key is present
         {
             Node* resnode = mp[key];
             int res = resnode->value;
             
             changePos(resnode);
             
             
             
             return res;
         }
        
        return -1;
    }
    
    void put(int key, int value) 
    {
             if(mp.find(key) != mp.end())
             {
                 Node* resnode = mp[key];
                 resnode->value = value;
                 
                 resnode->prev->next = resnode->next;
                 resnode->next->prev = resnode->prev;

                 resnode->next = head->next;
                 head->next = resnode;
                 resnode->next->prev = resnode;
                 resnode->prev = head;
                   
             }
        else
        {
            if(mp.size() == cap)
            {
                Node* resnode = tail->prev;
                mp.erase(resnode->key);
                resnode->key = key;
                resnode->value = value;
                mp[key] = resnode;
                
                 resnode->prev->next = resnode->next;
                 resnode->next->prev = resnode->prev;

                 resnode->next = head->next;
                 head->next = resnode;
                 resnode->next->prev = resnode;
                 resnode->prev = head;
            }
            else
            {
                 Node* temp = new Node(key, value);
                 mp[key] = temp;
                 
                 temp->next = head->next;
                 head->next = temp;
                 temp->next->prev = temp;
                 temp->prev = head;   
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */