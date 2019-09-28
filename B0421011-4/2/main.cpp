#include <iostream>
#include "seqList.h"

using namespace std;

int main() {
    seqList<int> list(2);
    list.insert(0, 1);
    list.insert(0, 2);
    list.traverse();
}
