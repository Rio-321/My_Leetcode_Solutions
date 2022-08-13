class Node{
public:
    
    int key;
    int value;
    int cnt;
    Node* next;
    Node* prev;
    
    Node(int key, int value)
    {
        this->key = key;
        this->value = value;
        this->cnt = 1;
        next = NULL;
        prev = NULL;
    }
    
};


class List
{
public:
    
    Node* head;
    Node* tail;
    int size;
    
    List()
    {
        head = new Node(0,0);
        tail = new Node(0,0);
        head->next = tail;
        tail->prev = head;
        size = 0;  
    }
    
    void addFront(Node* resnode)
    {
        Node* temp = head->next;
        resnode->next = temp;
        resnode->prev = head;
        head->next = resnode;
        temp->prev = resnode;
        size++;
    }
    
    void removeNode(Node* resnode)
    {
        Node* delprev = resnode->prev;
        Node* delnext = resnode->next;
        delprev->next = delnext;
        delnext->prev = delprev;
        size--;
    } 
    
};

class LFUCache {
public:
    
    map<int, Node*> keyNode;
    map<int, List*> freqListMap;
    int minFreq;
    int curSize;
    int maxSizeCache;
    
    
    LFUCache(int capacity) {
        maxSizeCache = capacity;
        curSize = 0;
        minFreq = 0;
    }
    
    void updateFreqListMap(Node* resnode)
    {   
        keyNode.erase(resnode->key);
        freqListMap[resnode->cnt]->removeNode(resnode);
        
        if(resnode->cnt == minFreq && freqListMap[resnode->cnt]->size == 0)
            minFreq++;
        
        List* nextHigherFreqList = new List();
        if(freqListMap.find(resnode->cnt+1) != freqListMap.end())
        {
            nextHigherFreqList = freqListMap[resnode->cnt+1];
        }
        
        resnode->cnt += 1;
        nextHigherFreqList->addFront(resnode);
        freqListMap[resnode->cnt] = nextHigherFreqList;
        keyNode[resnode->key] = resnode;
    }
    
    int get(int key) {
        
        if(keyNode.find(key) != keyNode.end())
        {
            Node* resnode = keyNode[key];
            int ans = resnode->value;
            updateFreqListMap(resnode);
            return ans;
        }
        
        return -1;
        
    }
    
    void put(int key, int value) {
        
        if(maxSizeCache == 0)
            return;
        
        if(keyNode.find(key) != keyNode.end())
        {
            Node* resnode = keyNode[key];
            resnode->value = value;
            updateFreqListMap(resnode);
        }
        else
        {
            
            if(curSize == maxSizeCache)
            {
                List* list = freqListMap[minFreq];
                keyNode.erase(list->tail->prev->key);
                freqListMap[minFreq]->removeNode(list->tail->prev);
                curSize--;
            }
            
            curSize++;
            minFreq = 1;
            
            List* listFreq = new List();
            if(freqListMap.find(minFreq) != freqListMap.end())
                listFreq = freqListMap[minFreq];
            
            Node* resnode = new Node(key, value);
            listFreq->addFront(resnode);
            keyNode[key] = resnode;
            freqListMap[minFreq] = listFreq;
        }
        
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */