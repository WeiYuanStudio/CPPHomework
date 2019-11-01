#include<iostream>
#include "linkQueue.h"

using namespace std;

int main() {
    linkQueue<int> linkQueue;
    
    for (int i = 0; i < 10; ++i) {
        linkQueue.enQueue(i);
    }

    while (!linkQueue.empty()) {
        cout << linkQueue.deQueue() << " ";
    }

    cout << endl;
}
