class Node{
public:
	int key;
	int value;
	int cnt;
	Node* prev;
	Node* next;

	Node(int key, int value)
	{
		this->key = key;
		this->value = value;
		this->cnt = 1;
		prev = NULL;
		next = NULL;
	}
};

class List{
public:
	int size;
	Node* head;
	Node* tail;

	List()
	{
		head = new Node(-1, -1);
		tail = new Node(-1, -1);
		head->next = tail;
		tail->next = head;
		size = 0;
	}

	void addFront(Node *node)
	{
		node->next = head->next;
		node->next->prev = node;
		head->next = node;
		node->prev = head;
		size++;
	}

	void removeNode(Node *node)
	{
		node->prev->next = node->next;
		node->next->prev = node->prev;
		size--;
	}
};


class LFUCache {
public:
    
    int minFreq;
	int curSize;
	int maxSizeCache;
	map<int,Node*> keyNode; // key - Node address
	map<int, List*> freqListMap; // freq - list address

    
    LFUCache(int capacity) {
        
        maxSizeCache = capacity;
		minFreq = 0;
		curSize = 0;

    }
    
  void updateFreqListMap(Node* node)
	{
		keyNode.erase(node->key);
		freqListMap[node->cnt]->removeNode(node);

		if(node->cnt == minFreq && freqListMap[minFreq]->size == 0)
				minFreq++;

		List* nextHigherFreqList = new List();
		if(freqListMap.find(node->cnt+1) != freqListMap.end())
					nextHigherFreqList = freqListMap[node->cnt +1];

		 node->cnt += 1;
		 nextHigherFreqList->addFront(node);
		 freqListMap[node->cnt] = nextHigherFreqList;
		 keyNode[node->key] = node;
	}
    
    int get(int key)
	{
		if(keyNode.find(key) != keyNode.end())
		{
			Node* node = keyNode[key];
			int val = node->value;
			updateFreqListMap(node);
			return val;
		}

		return -1;
	}
    
    void put(int key, int value)
	{
		if(maxSizeCache == 0)
			return;

		if(keyNode.find(key) != keyNode.end())
		{
			Node* node = keyNode[key];
			node->value = value;
			updateFreqListMap(node);
		}
		else
		{
			if(curSize == maxSizeCache)
			{
				List* list = freqListMap[minFreq];
				keyNode.erase(list->tail->prev->key);
				list->removeNode(list->tail->prev);
				curSize--;
			}

			curSize++;

			// new value has to be added who is not there previously

			minFreq = 1;
			List* listfreq = new List();
			if(freqListMap.find(minFreq) != freqListMap.end())
				 listfreq = freqListMap[minFreq];

			Node* node = new Node(key, value);
			listfreq->addFront(node);
			keyNode[key] = node;
			freqListMap[minFreq] = listfreq;
		}
	}
};



/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */