//
// Created by roybo on 3/5/2026.
//

#ifndef GREEDYCACHE_CACHE_H
#define GREEDYCACHE_CACHE_H

#include "Item.h"
#include <string>
#include <vector>
using namespace std;

class Cache {
    int age;
    int cache_size;
    vector<Item> raw_cache;

    int FIFO();
    int LRU();
    int OPTFF();

public:
    Cache(int cache_size);

    bool itemExists(int value);
    void insertItem(int value, const string& algorithm);

};


#endif //GREEDYCACHE_CACHE_H
