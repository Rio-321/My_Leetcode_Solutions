// https://leetcode.com/problems/insert-delete-getrandom-o1-duplicates-allowed/discuss/1708946/C%2B%2B-solution-using-Vector-and-Unordered-map!
class RandomizedCollection {
public:
    
    vector<pair<int,int>> arr;
    unordered_map<int, vector<int>> mp;
    
    RandomizedCollection() {
        
        
    }
    
    bool insert(int val) {
        
        auto it = mp.find(val);
        if(it == mp.end()) // element is not present
        {
            mp[val].push_back(arr.size());
            arr.push_back(make_pair(val, mp[val].size()-1));
            return true;
        }
        else
        {
            mp[val].push_back(arr.size());
            arr.push_back(make_pair(val, mp[val].size()-1));
            return false;
        }
        
            
    }
    
    bool remove(int val) {
        auto it = mp.find(val);
        if(it != mp.end())  // element is present
        {
            auto last = arr.back();
            int ind = mp[val].back();
            
            arr[ind] = last;
            mp[last.first][last.second] = ind;
            mp[val].pop_back();
            
            if(mp[val].empty())
                mp.erase(val);
            
            arr.pop_back();
            return true;
        }
        
        return false;
        
      
        
    }
    
    int getRandom() {
        
        // srand(time(0));  // answer will be getting wrong due to this
        int ind = (rand() % arr.size());
        
        return arr[ind].first;
        
     
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */