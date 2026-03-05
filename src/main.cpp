#include "utilities.h"
#include "Cache.h"
#include <iostream>
using namespace std;

int main() {
    // Ask how the user wants to input data into the program.
    string choice;
    string algorithm;

    cout << "Welcome to the Cache Simulator!" << endl;
    while (true) {
        cout << "Which replacement algorithm would you like to use?" << endl;
        cout << "1. First (FIFO)" << endl;
        cout << "2. Least Recently Used (LRU)" << endl;
        cout << "3. Belady's Farthest-In-Future, Optimal Offline (OPTFF)" << endl;
        cin >> choice;

        if (choice == "1") {
            choice = "FIFO";
        } else if (choice == "2") {
            choice = "LRU";
        } else if (choice == "3") {
            choice = "OPTFF";
        }

        if ((choice == "FIFO") || (choice == "LRU") || (choice == "OPTFF")) {
            algorithm = choice;
            break;
        } else {
            cout << "Please choose a valid option." << endl;
        }
    }

    choice.clear();
    while (true) {
        cout << "How will you input the data about the cache and its requests?" << endl;
        cout << "1. Manually" << endl;
        cout << "2. Read a file" << endl;
        cout << "3. Randomly generate data" << endl;
        cin >> choice;
        if ((choice == "1") || (choice == "2") || (choice == "3")) {
            break;
        } else {
            cout << "Please choose a valid option." << endl;
        }
    }

    tuple<int, vector<int>> data;

    if (choice == "1") {
        data = read_manually();
    } else if (choice == "2") {
        data = read_from_file();
    } else if (choice == "3") {
        data = generate_data();
    }

    Cache cache = Cache(get<0>(data), algorithm);
    vector<int> stream = get<1>(data);

    for (auto item : stream) {
        cache.accessItem(item);
    }
    cache.display();

    return 0;
}
