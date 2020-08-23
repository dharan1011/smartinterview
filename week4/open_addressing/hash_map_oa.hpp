//
// Created by Dharan Aditya on 23/08/20.
// Warning : Works only for fixed Size
//

#ifndef DSA_HASH_MAP_OA_H
#define DSA_HASH_MAP_OA_H

#include <vector>
#include <cmath>
#include <climits>
class hash_map_oa {
private:
    const int DELETED = INT_MAX;
    const int EMPTY = INT_MIN;
    const int load_factor = 10;
    int S;
    std::vector<int>* ht;

    [[nodiscard]] int hash_linear_probe(int key, int i) const;

    [[nodiscard]] int hash_quadratic_probe(int key, int i) const;
    int _search(int key);
    int _size;
public:
    explicit hash_map_oa(int s);

    ~hash_map_oa();

    void insert(int key);

    void remove(int key);

    bool search(int key);

    [[nodiscard]] int size() const;
};

hash_map_oa::hash_map_oa(int inputSize) {
    this->S = inputSize * load_factor;
    ht = new std::vector<int>(this->S, EMPTY);
    this->_size = 0;
}

hash_map_oa::~hash_map_oa() {
    delete ht;
}

int hash_map_oa::hash_linear_probe(int key, int i) const {
    key = abs(key);
    return (key + i) % this->S;
}

int hash_map_oa::hash_quadratic_probe(int key, int i) const {
    key = abs(key);
    return (key + (i * i)) % this->S;
}

void hash_map_oa::insert(int key) {
    int i = 0;
    int tabel_index = hash_quadratic_probe(key, i);
    while ((*ht)[tabel_index] != EMPTY && (*ht)[tabel_index] != DELETED){
        tabel_index = hash_quadratic_probe(key, ++i);
    }
    (*ht)[tabel_index] = key;
}

bool hash_map_oa::search(int key) {
    return _search(key) != EMPTY;
}

int hash_map_oa::_search(int key) {
    int i = 0;
    int table_index = hash_quadratic_probe(key, i);
    while ((*ht)[table_index] != EMPTY){
        if((*ht)[table_index] == key){
            return table_index;
        }
        table_index = hash_quadratic_probe(key, ++i);
    }
    return EMPTY;
}

void hash_map_oa::remove(int key){
    int i = 0;
    int ele_index = _search(key);
    if(ele_index != EMPTY){
        (*ht)[ele_index] = DELETED;
    }
}


#endif //DSA_HASH_MAP_OA_H
