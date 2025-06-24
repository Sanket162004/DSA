class RandomizedSet {

    unordered_map<int, int> val_to_idx;

    vector<int> values; 


public:
    RandomizedSet() {}
    
    bool insert(int val) {
        if (val_to_idx.count(val)) {
            return false;
        }

        // Add to the back of the vector
        // update the maps

        values.push_back(val);
        val_to_idx[val] = values.size() - 1;
        return true;
    }
    
    bool remove(int val) {
        if (!val_to_idx.count(val)) {
            return false;
        }

        // Use the last value to swap
        
        // get the idx we are removing
        int removed_idx = val_to_idx[val];
        
        // get the last value of the vector
        int last_val = values.back();

        // do the swap
        values[removed_idx] = last_val;
        val_to_idx[last_val] = removed_idx;
        
        // back is a copy now, remove it
        values.pop_back();

        // remove vals map entry
        val_to_idx.erase(val);
        return true;

    }
    
    int getRandom() {
        int random = rand() % values.size();
        return values[random];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */