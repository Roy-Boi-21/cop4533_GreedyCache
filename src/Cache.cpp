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
    int remove_index = -1;
    int oldest_access = -2147483648;
    for (int i = 0; i < raw_cache.size(); i++) {
        int current_access = raw_cache[i].get_access();
        if (current_access > oldest_access) {
            oldest_access = current_access;
            remove_index = i;
        }
    }
    return remove_index;
}

int Cache::OPTFF(const vector<int>& stream) {
    // Belady's algorithm looks ahead in the requests to see which item should be dropped.
    int remove_index = raw_cache.size() - 1;
    set<int> unmatched;
    for (auto item : raw_cache) {
        unmatched.insert(item.get_value());
    }

    for (int i = age; i < stream.size(); i++) {
        if (unmatched.count(stream[i])) {
            unmatched.erase(stream[i]);
        }

        if (unmatched.size() <= 1) {
            break;
        }
    }

    if (!unmatched.empty()) {
        // If there are multiple numbers in the set, evict the last number from the cache.
        int remove_number = *(unmatched.end()--);
        for (int i = 0; i < raw_cache.size(); i++) {
            Item item = raw_cache[i];
            if (item.get_value() == remove_number) {
                remove_index = i;
            }
        }
    }

    return remove_index;
}

int Cache::insert_item(int value, const vector<int>& stream) {
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
        i = OPTFF(stream);
    } else {
        throw exception();
    }

    raw_cache[i].assign_data(value, age);
    age++;
    return i;
}

Cache::Cache(int cache_size, string algorithm) {
    this->age = 0;
    this->cache_size = cache_size;
    this->cache_hits = 0;
    this->cache_misses = 0;
    this->algorithm = algorithm;
    raw_cache.reserve(cache_size);
}

int Cache::access_item(int value, const vector<int>& stream) {
    int itemIndex = -1;
    for (int i = 0; i < raw_cache.size(); i++) {
        if (raw_cache[i].peek() == value) {
            itemIndex = i;
            cache_hits++;
        }
    }

    if (itemIndex == -1) {
        itemIndex = insert_item(value, stream);
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

    cout << endl;
}

void Cache::display_hit_rate() {
    cout << "Algorithm:      " << algorithm << endl;
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
}

int Cache::get_misses() {
    return cache_misses;
}

string Cache::get_algorithm() {
    return algorithm;
}
