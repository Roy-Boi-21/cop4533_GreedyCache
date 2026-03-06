//
// Created by roybo on 3/5/2026.
//

#include "utilities.h"

tuple<int, vector<int>> read_manually() {
    int cache_capacity = -1;
    while (cache_capacity < 0) {
        try {
            string input;
            cout << "What is the size of the cache?" << endl;
            cin >> input;
            cache_capacity = stoi(input);
        } catch (...) {
            cout << "Invalid input.  Please enter a positive integer." << endl;
        }
    }

    int request_count = -1;
    while (request_count < 0) {
        try {
            string input;
            cout << "How many requests will the cache receive?" << endl;
            cin >> input;
            request_count = stoi(input);
        } catch (...) {
            cout << "Invalid input.  Please enter a positive integer." << endl;
        }
    }

    vector<int> requests;
    requests.reserve(request_count);
    for (int i = 0; i < request_count; i++) {
        try {
            string input;
            cout << "What is the next request for the cache?  (" << i + 1 << "/" << request_count << ")" << endl;
            cin >> input;
            requests.emplace_back(stoi(input));
        } catch (...) {
            cout << "Invalid input.  Please enter an integer." << endl;
            i--;
        }
    }

    return {cache_capacity, requests};
}

vector<int> line_to_numbers(const string& line) {
    vector<int> numbers;
    string substr;
    for (auto c : line) {
        if ((c == ' ') || (c == '\n')) {
            numbers.push_back(stoi(substr));
            substr.clear();
        } else {
            substr += c;
        }
    }
    if (!substr.empty()) {
        numbers.push_back(stoi(substr));
    }
    return numbers;
}

tuple<int, vector<int>> read_from_file() {
    string filename;
    ifstream file;
    while (true) {
        cout << "Enter the name of the file to read in:  (\"example.txt\")" << endl;
        cin >> filename;
        file.open(filename);
        if (file.good()) {
            break;
        } else {
            cout << "ERROR: File not found." << endl;
        }
    }

    string line;
    getline(file, line);
    vector<int> header = line_to_numbers(line);
    int cache_capacity = header[0];
    int request_count = header[1];

    getline(file, line);
    vector<int> stream = line_to_numbers(line);

    if (request_count != stream.size()) {
        throw exception();
    }

    return {cache_capacity, stream};
}

tuple<int, vector<int>> generate_data() {
    int cache_capacity = -1;
    while (cache_capacity < 0) {
        try {
            string input;
            cout << "What is the size of the cache?" << endl;
            cin >> input;
            cache_capacity = stoi(input);
        } catch (...) {
            cout << "Invalid input.  Please enter a positive integer." << endl;
        }
    }

    int request_count = -1;
    while (request_count < 0) {
        try {
            string input;
            cout << "How many requests will the cache receive?" << endl;
            cin >> input;
            request_count = stoi(input);
        } catch (...) {
            cout << "Invalid input.  Please enter a positive integer." << endl;
        }
    }

    int upper_bound = -1;
    while (upper_bound < 1) {
        try {
            string input;
            cout << "What should be the upper bound of inputs be?  (1 to X)" << endl;
            cin >> input;
            upper_bound = stoi(input);

        } catch (...) {
            cout << "Invalid input.  Please enter an integer greater than or equal to 1." << endl;
        }
    }

    srand((unsigned) time(nullptr));
    vector<int> stream;
    stream.reserve(request_count);

    for (int i = 0; i < request_count; i++) {
        stream.emplace_back((rand() % upper_bound) + 1);
    }

    return {cache_capacity, stream};
}

void write_to_file(vector<Cache> caches, string filename) {
    int LEFT_SIDE_WIDTH = 6;

    ofstream file(filename);
    for (auto cache : caches) {
        string algorithm = cache.get_algorithm();
        file << algorithm;
        for (int i = algorithm.size(); i < LEFT_SIDE_WIDTH; i++) {
            file << ' ';
        }
        file << ": " << cache.get_misses() << endl;
    }
    cout << "Cache misses written to \"" << filename << "\"" << endl;
}
