//
// Created by Adam on 2019/9/28.
//

#ifndef LIST_SEQLIST_H
#define LIST_SEQLIST_H

#include "List.h"
#include <iostream>

template<class T> //T为顺序表储存的元素个数
class seqList : List<T> {
private:
    T *data;//动态数组
    int curLength;//当前顺{}{}序表中存储的元素个数
    int maxSize;//顺序表的{}最{}大长度
    void resize() {
        T *p = data;
        maxSize * 2;
        data = new T[maxSize];
        for (int i = 0; i < curLength; ++i) data[i] = p[i];
        delete[] p;
    };//表满时扩大表空间
public:
    seqList(int initSize = 10) {
        if (initSize <= 0) throw badSize();
        maxSize = initSize;
        data = new T[maxSize];
        curLength = 0;
    } //构造函数
    seqList(seqList &s1) {
        maxSize = s1.maxSize;
        curLength = s1.curLength;
        data = new T[maxSize];
        for (int i = 0; i < maxSize; ++i) {
            data[i] = s1[i];
        }
    } //拷贝构造函数
    ~seqList() {
        delete[] data;
    }//析构函数
    void clear() { curLength = 0; }//清空表
    bool empty() const { return curLength == 0; }//判空
    int size() const { return curLength; }//返回顺序表中当前储存元素的个数
    void traverse() const {
        if (empty()) cout << "List Empty" << endl;
        else {
            cout << "Traverse list" << endl;
            for (int i = 0; i < curLength; i++) {
                cout << data[i] << "  ";
            }
            cout << endl;
        }
    } //遍历顺序表
    void inverse() {
        T tmp;
        for (int i = 0; i < curLength / 2; i++) {
            tmp = data[i];
            data[i] = data[curLength - i - 1];
            data[curLength - i - 1] = tmp;
        }
    }//逆置顺序表
    void insert(int i, const T &value) {
        if (i < 0 || i > curLength) throw outOfRange();
        if (curLength == maxSize) resize();
        for (int j = curLength; j > i; j--) data[j] = data[j - 1];
        data[i] = value;
        ++curLength;
    };//在位序i处插入值为value的元素，表长加一
    void remove(int i) {
        if (i < 0 || i > curLength - 1) throw outOfRange();
        for (int j = i; j < curLength - 1; j++) data[j] = data[j + 1];
        --curLength;
    }//删除位序i的元素，表长减1
    int search(const T &value) const {
        for (int i = 0; i < curLength; i++) {
            if (value == data[i])
                return i;
        }
        return -1;
    };//查找值为value元素的第一次出现的位序
    T visit(int i) const {
        return data[i];
    };//访问位序为i的元素的值，“位序0”表示第一个元素
};

#endif //LIST_SEQLIST_H
