#include<iostream>
#include "linkStack.h"

int main() {
    linkStack<int> stack1;
    stack1.push(1);
    stack1.push(2);
    cout << stack1.pop() << stack1.pop() << endl;
}
