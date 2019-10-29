#ifndef LINKSTACK_H
#define LINKSTACK_H

#include <iostream>
#include "Stack.h"

using namespace std;

template <class T> class linkStack : public Stack<T> {
private:
    struct Node {
        T data; //数据
        Node* next;
        Node() {
            next = nullptr;
        }
        Node(const T &value, Node *p = nullptr) {
            data = value;
            next = p;
        }
    };
    Node *top; //栈顶
public:
    linkStack() { top = nullptr; } //构造空链
    ~linkStack() { clear(); }
    void clear();
    bool empty()const { return top == nullptr; } //判空
    int size()const; //求长度
    void push(const T &value); //压栈
    T pop(); //出栈
    T getTop()const; //获得顶元素
};

template<class T>
void linkStack<T>::clear() { //清空栈
    Node* p; //p指针暂存栈顶
    while (top != nullptr){
        p = top;
        top = top->next; //top指针移动
        delete p;
    }
}

template<class T>
int linkStack<T>::size() const { //获取栈长度
    Node *p = top;
    int count = 0;
    while (p){
        count++;
        p = p->next;
    }
    return count;
}

template<class T>
void linkStack<T>::push(const T &value) {
    Node *p = new Node(value, top); //data, next
    top = p; //刷新栈顶指针
}

template<class T>
T linkStack<T>::pop() { //出栈
    if(empty())
        throw outOfRange();
    Node *p = top;
    T value = p->data; //复制data
    top = top->next; //头指针前移
    delete p; //删除栈顶元素
    return value; //返回data
}

template<class T>
T linkStack<T>::getTop() const { //获取栈顶元素
    if (empty())
        throw outOfRange();
    return top->data; //返回栈顶data
}

#endif //LINKSTACK_H
