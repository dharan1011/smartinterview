//
// Created by Dharan Aditya on 23/08/20.
//

#ifndef DSA_HASH_MAP_SC_H
#define DSA_HASH_MAP_SC_H
#include <list>
#include <utility>
#include <climits>
#include <algorithm>
/*
 * Hash Map Implementation using Separate Chaining
 * */
class hash_map_sc {
    int S;
    std::list<std::pair<int,int>> *ht;
    [[nodiscard]] int hash(int key) const;
    std::list<std::pair<int,int>>::iterator _search(int key, int ht_index);
    int _size;
public:
    explicit hash_map_sc(int s);
    ~hash_map_sc();
    void insert(int key);
    void remove(int key);
    bool search(int key);
    [[nodiscard]] int size() const;
};

hash_map_sc::hash_map_sc(int s) : S(s), _size(0) {
    ht = new std::list<std::pair<int,int>>[s];
}

hash_map_sc::~hash_map_sc() {
    delete [] ht;
}

int hash_map_sc::hash(int key) const {
    return key % this->S;
}

std::list<std::pair<int,int>>::iterator hash_map_sc::_search(int key, int ht_index) {
    auto itr = ht[ht_index].begin();
    for(;itr != ht[ht_index].end(); itr++){
        if(itr->first == key){
            break;
        }
    }
    return itr;
}

void hash_map_sc::insert(int key) {
    int ht_index = hash(key);
    auto pos = _search(key, ht_index);
    if(pos != ht[ht_index].end()){
        pos->second++;
    }else{
        ht[ht_index].emplace_back(key, 1);
        _size++;
    }
}

bool hash_map_sc::search(int key) {
    int hash_val = hash(key);
    return _search(key, hash_val) != ht[hash_val].end();
}

void hash_map_sc::remove(int key) {
    int ht_index = hash(key);
    auto pos = _search(key, ht_index);
    if(pos != ht[ht_index].end()){
        pos->second--;
        if(pos->second == 0){
            ht[ht_index].remove(std::make_pair(key, 0));
            _size--;
        }
    }
}

int hash_map_sc::size() const {
    return _size;
}


#endif //DSA_HASH_MAP_SC_H
