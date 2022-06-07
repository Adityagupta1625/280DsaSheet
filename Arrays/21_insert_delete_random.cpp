// RandomizedCollection is a data structure that contains a collection of numbers, possibly duplicates (i.e., a multiset). It should support inserting and removing specific elements and also removing a random element.

// Implement the RandomizedCollection class:

// RandomizedCollection() Initializes the empty RandomizedCollection object.
// bool insert(int val) Inserts an item val into the multiset, even if the item is already present. Returns true if the item is not present, false otherwise.
// bool remove(int val) Removes an item val from the multiset if present. Returns true if the item is present, false otherwise. Note that if val has multiple occurrences in the multiset, we only remove one of them.
// int getRandom() Returns a random element from the current multiset of elements. The probability of each element being returned is linearly related to the number of same values the multiset contains.
// You must implement the functions of the class such that each function works on average O(1) time complexity.

// Note: The test cases are generated such that getRandom will only be called if there is at least one item in the RandomizedCollection.
#include <bits/stdc++.h>
using namespace std;

class RandomizedCollection {
public:
    map<int,vector<int>> m;
    vector<pair<int,int>> v;
    RandomizedCollection() {
        
    }
    
    bool insert(int val) {
        if(m.find(val)==m.end()){
            m[val].push_back(v.size());
            v.push_back({val,m[val].size()-1});
            return true;
        }
        else{
            m[val].push_back(v.size());
            v.push_back({val,m[val].size()-1});
            return false;
        }
    }
    
    bool remove(int val) {
        auto it=m.find(val);
        
        if(it!=m.end()){
            auto last=v.back();
            m[last.first][last.second]=m[val].back();
            v[m[val].back()]=last;
            v.pop_back();
            m[val].pop_back();
            
            if(m[val].empty()) m.erase(val);
            
            return true;
        }
        return false;
    }
    
    int getRandom() {
        int idx=rand()%v.size();
        return v[idx].first;
    }
};