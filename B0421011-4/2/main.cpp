#include <iostream>
#include "seqList.h"
#include "linkList.h"

using namespace std;

int main() {
    cout << "Hello, World!" << endl;

    cout << "Use Seq List: " << endl;
    seqList<int> list(2);
    list.insert(0, 1);
    list.insert(0, 2);
    list.traverse();

    cout << "Use Link List" << endl;
    linkList<int> listB;
    listB.insert(0, 1);
    listB.insert(0, 2);
    listB.traverse();
}
