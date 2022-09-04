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
            this->key = key;
            this->value = value;
            
            prev = NULL;
            next = NULL;
        }
    };
    
    int cap;
    int count = 0;
    unordered_map<int, Node*> mp;
    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);

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
          resnode->next->prev = resnode;
          resnode->prev = head;
          head->next = resnode;
    }
 
    
    int get(int key) 
    {
        if(mp.find(key) != mp.end())
        {
            Node* curr = mp[key];
            int res = curr->value;
            
            changePos(curr);
            
            return res;
        }
        
        return -1;
    }
    
    void put(int key, int value) 
    {
           if(mp.find(key) != mp.end())
           {
               Node* curr = mp[key];
               curr->value = value;
               
               changePos(curr);
           }
            else
            {
                if(count == cap)
                {   
                    mp.erase(tail->prev->key);
                    mp[key] = tail->prev;

                    tail->prev->value = value;
                    tail->prev->key = key;
                    changePos(tail->prev);

                }
                else
                {
                    Node* newNode = new Node(key, value);
                    mp[key] = newNode;
                    count++;

                    head->next->prev = newNode;
                    newNode->next = head->next;
                    head->next = newNode;
                    newNode->prev = head;

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