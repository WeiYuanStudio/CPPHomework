#include <iostream>
#include "doubleLinkList.h"

using namespace std;

int main()
{
    cout << "创建双链表" << endl;
    doubleLinkList<int> list;

    cout << "插入0-9" << endl;
    for (int i = 0; i < 10; ++i) {
        list.insert(i, i);
    }

    cout << "遍历表" << endl;
    list.traverse();

    cout << "逆置表" << endl;
    list.inverse();

    cout << "遍历表" << endl;
    list.traverse();

    cout << "查找数字5" << endl;
    int index = list.search(5);
    cout << "Index: " << index << endl;

    cout << "删除该元素" << endl;
    list.remove(index);

    cout << "遍历表" << endl;
    list.traverse();

    cout << "清空表" << endl;
    list.clear();

    cout << "遍历表" << endl;
    list.traverse();
}
