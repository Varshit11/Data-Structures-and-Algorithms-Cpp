/* C++ program to design a data structure with Insert Delete GetRandom in O(1) time
Problem Statement - https://leetcode.com/problems/insert-delete-getrandom-o1/
*/

class RandomizedSet {
public:
    /** Initialize your data structure here. */
    unordered_map<int, int> m;
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(m.find(val) != m.end()) return false;
        else {
            m[val] = 1;
            return true;
        }
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(m.find(val) == m.end()) return false;
        else{
            m.erase(val);
            return true;
        }
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return next(m.begin(), rand()%m.size())->first;
    }
};
