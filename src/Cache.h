//
// Created by roybo on 3/5/2026.
//

#ifndef GREEDYCACHE_CACHE_H
#define GREEDYCACHE_CACHE_H

#include "Item.h"
#include <set>
#include <vector>
#include <iostream>
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
    int OPTFF(const vector<int>& stream);
    int insert_item(int value, const vector<int>& stream);

public:
    Cache(int cache_size, string algorithm);

    //int access_item(int value);
    int access_item(int value, const vector<int>& stream = vector<int>());
    void display();
    void display_hit_rate();

};


#endif //GREEDYCACHE_CACHE_H
