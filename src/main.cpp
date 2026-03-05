#include "Cache.h"
#include <iostream>
using namespace std;

int main() {
    Cache example = Cache(3, "FIFO");

    example.accessItem(1);
    example.accessItem(2);
    example.accessItem(3);
    example.display();

    example.accessItem(1);
    example.accessItem(1);
    example.accessItem(1);
    example.display();

    example.accessItem(4);
    example.display();

    return 0;
}
