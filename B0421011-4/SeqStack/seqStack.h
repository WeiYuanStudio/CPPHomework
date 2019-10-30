#include "Stack.h"

#ifndef SEQSTACK_H
#define SEQSTACK_H
using namespace std;
template <class T> class seqStack : public Stack<T> {
private:
    T *data; //数组指针
    int top; //栈顶下标
    int maxSize; //最大容量
    void resize(); //重新分配空间

public:
    seqStack(int initSize = 100);
    ~seqStack() { delete [] data; }
    void clear() { top = -1; }
    bool empty() const { return top == -1; }
    int size() const { return top+1; }
    void push(const T &value);
    T pop();
    T getTop() const;
    T getPop() const;
}; 

template<class T>
void seqStack<T>::resize() { //重新分配空间
    T *tmp = data; //指向旧数组
    data = new T[2 * maxSize]; //数组指针指向重新分配空间
    for (int i = 0; i < maxSize; ++i) { //转移数据
        data[i] = tmp[i];
    }
    maxSize*=2; //调整maxSize
    delete [] tmp; //删除旧数组
}

template<class T>
seqStack<T>::seqStack(int initSize) { //指定容量构造方法
    if(initSize <= 0)
        throw badSize();
    data = new T[initSize];
    maxSize = initSize;
    top = -1;
}

template<class T>
void seqStack<T>::push(const T &value) { //压栈
    if (top == maxSize-1) //栈顶超出容量重新分配空间
        resize();
    data[++top] = value; //栈顶下标自增，插入数据
}

template<class T>
T seqStack<T>::pop() { //出栈
    if (empty()) //检查是否空栈
        throw outOfRange();
    return data[top--]; //返回top下标数组元素，后自减下标
}

template<class T>
T seqStack<T>::getTop() const { //获取栈顶
    if (empty()) //检查是否空栈
        throw outOfRange();
    return data[top]; //返回栈顶
}

#endif //SEQSTACK_H
