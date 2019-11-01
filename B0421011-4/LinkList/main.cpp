#include <iostream>
#include "linkList.h"

using namespace std;

int main()
{
    cout << "创建链表" << endl;
    linkList<int> list;

    cout << "头插法0-4" << endl;
    for (int i = 4; i >= 0; --i){
        list.headCreate(i);
    }

    cout << "遍历表" << endl;
    list.traverse();

    cout << "尾插法5-9" << endl;
    for (int i = 5; i < 10; ++i) {
        list.tailCreate(i);
    }

    cout << "遍历表" << endl;
    list.traverse();

    cout << "转置表" << endl;
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

    cout << "插入-1到该元素地址" << endl;
    list.insert(index, -1);

    cout << "遍历表" << endl;
    list.traverse();

    cout << "删除表" << endl;
    list.clear();

    cout << "遍历表" << endl;
    list.traverse();
}
