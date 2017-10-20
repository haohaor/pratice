class RandomizedCollection {
public:
    map<int, int> myMap;
    /** Initialize your data structure here. */
    RandomizedCollection() {
        myMap.clear();
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        myMap[val] ++;
        if (myMap[val] == 1) {
            return true;
        } else {
            return false;
        }
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        if (myMap[val]) {
            myMap[val] --;
            return true;
        } 
        return false;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        vector<int> contain;
        for (auto it : myMap) {
            int cnt = it.second;
            while (cnt -- > 0) {
                contain.push_back(it.first);
            }
        }
        return contain[rand() % contain.size()];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection obj = new RandomizedCollection();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */