//
// Created by roybo on 3/5/2026.
//

#ifndef GREEDYCACHE_ITEM_H
#define GREEDYCACHE_ITEM_H


class Item {
    int value;
    int age;  // 0 : This item was the first item in the cache.
    int access_time;  // 0 : This item was just accessed.

public:
    Item();
    Item(int value, int age);

    void assign_data(int newValue, int newAge);
    int peek();
    int access();
    int get_value();
    int get_age();
    int get_access();

};


#endif //GREEDYCACHE_ITEM_H
