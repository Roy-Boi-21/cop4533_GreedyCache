//
// Created by roybo on 3/5/2026.
//

#include "Item.h"

Item::Item() {
    value = -1;
    age = -1;
    access_time = -1;
}

Item::Item(int value, int age) {
    assign_data(value, age);
}


void Item::assign_data(int newValue, int newAge) {
    this->value = newValue;
    this->age = newAge;
    access_time = 0;
}

int Item::peek() {
    access_time++;
    return value;
}

int Item::access() {
    access_time = 0;
    return value;
}

int Item::get_value() {
    return value;
}

int Item::get_age() {
    return age;
}

int Item::get_access() {
    return access_time;
}
