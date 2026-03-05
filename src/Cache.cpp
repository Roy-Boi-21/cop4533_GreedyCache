//
// Created by roybo on 3/5/2026.
//

#include "Cache.h"
using namespace std;

int Cache::FIFO() {
    throw exception();  // TODO
}

int Cache::LRU() {
    throw exception();  // TODO
}

int Cache::OPTFF() {
    throw exception();  // TODO
}

Cache::Cache(int cache_size) {
    this->age = 0;
    this->cache_size = cache_size;
    raw_cache.reserve(cache_size);
}

bool Cache::itemExists(int value) {
    bool foundItem = false;
    for (auto item : raw_cache) {
        if (item.peek() == value) {
            foundItem = true;
        }
    }
    return foundItem;
}

void Cache::insertItem(int value, const string& algorithm) {
    if (raw_cache.size() < cache_size) {
        raw_cache.emplace_back(value, 0);
        age++;
        return;
    }

    int i = -1;
    if (algorithm == "FIFO") {
        i = FIFO();
    } else if (algorithm == "LRU") {
        i = LRU();
    } else if (algorithm == "OPTFF") {
        i = OPTFF();
    } else {
        throw exception();
    }

    raw_cache[i].assign_data(value, age);
    age++;
}
