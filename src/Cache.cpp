//
// Created by roybo on 3/5/2026.
//

#include "Cache.h"
using namespace std;

int Cache::FIFO() {
    int remove_index = -1;
    int oldest_age = 2147483647;
    for (int i = 0; i < raw_cache.size(); i++) {
        int current_age = raw_cache[i].get_age();
        if (current_age < oldest_age) {
            oldest_age = current_age;
            remove_index = i;
        }
    }
    return remove_index;
}

int Cache::LRU() {
    throw exception();  // TODO
}

int Cache::OPTFF() {
    throw exception();  // TODO
}

Cache::Cache(int cache_size, string algorithm) {
    this->age = 0;
    this->cache_size = cache_size;
    this->cache_hits = 0;
    this->cache_misses = 0;
    this->algorithm = algorithm;
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

int Cache::insertItem(int value) {
    if (raw_cache.size() < cache_size) {
        raw_cache.emplace_back(value, age);
        return age++;
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
    return i;
}

int Cache::accessItem(int value) {
    int itemIndex = -1;
    for (int i = 0; i < raw_cache.size(); i++) {
        if (raw_cache[i].peek() == value) {
            itemIndex = i;
            cache_hits++;
        }
    }

    if (itemIndex == -1) {
        itemIndex = insertItem(value);
        cache_misses++;
    }

    raw_cache[itemIndex].access();
    return itemIndex;
}

void Cache::display() {
    for (int i = 0; i < raw_cache.size(); i++) {
        Item& current_item = raw_cache[i];
        cout << "===== Element " << i << " =====" << endl;
        cout << " - Value:         " << current_item.get_value() << endl;
        cout << " - Age:           " << current_item.get_age() << endl;
        cout << " - Last Accessed: " << current_item.get_access() << endl;
    }

    cout << "Cache hits:     " << cache_hits << endl;
    cout << "Cache misses:   " << cache_misses << endl;
    if ((cache_hits + cache_misses) > 0) {
        cout << "Cache hit rate: " << cache_hits << '/' << cache_hits + cache_misses
        << " (" << 100.0f * (float(cache_hits) / float(cache_hits + cache_misses)) << "%)" << endl;
    } else {
        cout << "Cache hit rate not defined." << endl;
    }

    if (raw_cache.size() < cache_size) {
        cout << "This cache can hold " << cache_size - raw_cache.size() << " more items." << endl;
    }
    cout << endl;
}
