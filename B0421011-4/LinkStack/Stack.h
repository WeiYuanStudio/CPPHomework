#ifndef STACK_H
#define STACK_H

#include <exception>
using namespace std;

template <class T>
class Stack{
public:
    virtual bool empty() const = 0; //判空
    virtual int size() const = 0; //求栈中元素
    virtual void push(const T &x) = 0; //压栈
    virtual T pop() = 0; //出栈
    virtual T getTop() const = 0; //获取栈顶
    virtual void clear() = 0; //清空栈
    virtual ~Stack() {} //析构
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

#endif //STACK_H
