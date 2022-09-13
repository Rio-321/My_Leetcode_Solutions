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


class LRUCache{
public:
    
    int cap;
    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);
    unordered_map<int, Node*> keyMap;
    
    LRUCache(int capacity)
    {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    void changePos(Node* curNode)
    {
        curNode->prev->next = curNode->next;
        curNode->next->prev = curNode->prev;
        
        curNode->next = head->next;
        head->next = curNode;
        
        curNode->next->prev = curNode;
        curNode->prev = head;
    }
    
    int get(int key)
    {
        if(keyMap.find(key) != keyMap.end())
        {
            Node* curr = keyMap[key];
            int val = curr->value;
            changePos(curr);
            return val;
        }
        
        return -1;
    }
    
    
    void put(int key, int value)
    {
        if(keyMap.find(key) != keyMap.end())  
        {
            Node* temp = keyMap[key];
            temp->value = value;
            changePos(temp);
        }
        else
        {
            if(keyMap.size() == cap)
            {
                Node* temp = tail->prev;
                keyMap.erase(temp->key);
                
                temp->key = key;
                temp->value = value;
                changePos(temp); 
                
                keyMap[key] = temp;
                
            }
            else
            {
                Node* newNode = new Node(key, value);
            
                newNode->next = head->next;
                head->next = newNode;
                newNode->next->prev = newNode;
                newNode->prev = head;
                
                keyMap[key] = newNode;
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