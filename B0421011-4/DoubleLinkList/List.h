//
// Created by Adam on 2019/9/27.
//

#ifndef LIST_LIST_H
#define LIST_LIST_H

#include <exception>

using namespace std;

template<class T>
class List {
public:
    virtual void clear() = 0; //清空线性表
    virtual bool empty() const = 0;//判空
    virtual int size() const = 0; //求线性表长度
    virtual void insert(int i, const T &value) = 0;//在位序i处插入值为value的元素
    virtual void remove(int i) = 0;//删除位序i处的元素
    virtual int search(const T &value) const = 0;//查找值为value的元素第一次出现的位序
    virtual T visit(int i) const = 0; //查找位序为i的元素并返回
    virtual void traverse() const = 0; //遍历线性表
    virtual void inverse() = 0;//逆置线性表
    virtual ~List() {};
};

class outOfRange : public exception {
public:
    const char *what() const throw() {
        return "ERROR! Out of Range.\n";
    }
};

class badSize : public exception {
public:
    const char *what() const throw() {
        return "ERROR! Bad type.\n";
    };
};

#endif //LIST_LIST_H
