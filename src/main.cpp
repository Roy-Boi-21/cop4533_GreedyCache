#include "utilities.h"
#include "Cache.h"
#include <iostream>
using namespace std;

int main() {
    const string DIVIDER = "================================================================";
    string choice;
    string filename;

    cout << "Welcome to the Cache Simulator!" << endl;
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

    cout << "What will be the name of the output file?" << endl;
    cin >> filename;
    if (filename.empty()) {
        filename = "output.txt";
    }


    tuple<int, vector<int>> data;

    if (choice == "1") {
        data = read_manually();
    } else if (choice == "2") {
        data = read_from_file();
    } else if (choice == "3") {
        data = generate_data();
    }

    Cache fifo = Cache(get<0>(data), "FIFO");
    Cache lru = Cache(get<0>(data), "LRU");
    Cache optff = Cache(get<0>(data), "OPTFF");
    vector<int> stream = get<1>(data);

    for (auto item : stream) {
        fifo.access_item(item);
        lru.access_item(item);
        optff.access_item(item, stream);
    }

    cout << DIVIDER << endl;
    fifo.display_hit_rate();
    lru.display_hit_rate();
    optff.display_hit_rate();
    cout << DIVIDER << endl;

    vector<Cache> caches = {fifo, lru, optff};
    write_to_file(caches, filename);

    return 0;
}
