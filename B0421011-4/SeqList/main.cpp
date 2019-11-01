#include <iostream>
#include "seqList.h"

using namespace std;

int main()
{
    cout << "创建顺序表，长度为10" << endl;
    seqList<int> list(10);

    cout << "插入0-9" << endl;
    for (int i = 0; i < 10; ++i)
    {
        list.insert(i, i);
    }

    cout << "求线性表长度" << endl;
    cout << list.size() << endl;

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

    cout << "插入新元素100使表容量不足，这将会自动调用Resize()" << endl;
    list.insert(0, 100);

    cout << "遍历表" << endl;
    list.traverse();

    cout << "删除表" << endl;
    list.clear();

    cout << "遍历表" << endl;
    list.traverse();
}
