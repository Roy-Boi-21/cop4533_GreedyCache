//
// Created by roybo on 3/5/2026.
//

#ifndef GREEDYCACHE_CACHE_H
#define GREEDYCACHE_CACHE_H

#include "Item.h"
#include <iostream>
#include <vector>
using namespace std;

class Cache {
    int age;
    int cache_size;
    int cache_hits;
    int cache_misses;
    string algorithm;
    vector<Item> raw_cache;

    int FIFO();
    int LRU();
    int OPTFF();

public:
    Cache(int cache_size, string algorithm);

    bool itemExists(int value);
    int insertItem(int value);
    int accessItem(int value);
    void display();

};


#endif //GREEDYCACHE_CACHE_H
