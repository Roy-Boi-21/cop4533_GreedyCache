//
// Created by roybo on 3/5/2026.
//

#ifndef GREEDYCACHE_UTILITIES_H
#define GREEDYCACHE_UTILITIES_H


#include "Cache.h"
#include <tuple>
#include <vector>
#include <fstream>
#include <iostream>
using namespace std;

tuple<int, vector<int>> read_manually();
vector<int> line_to_numbers();
tuple<int, vector<int>> read_from_file();
tuple<int, vector<int>> generate_data();
void write_to_file(vector<Cache> caches, string filename = "output.txt");


#endif //GREEDYCACHE_UTILITIES_H
