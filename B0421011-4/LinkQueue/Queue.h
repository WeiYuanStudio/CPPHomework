#ifndef QUEUE_H
#define QUEUE_H

#include <exception>
using namespace std;

template<class T>
class Queue {
public:
    virtual bool empty() const = 0; //判空

    virtual void clear() = 0; //清空队列

    virtual int size() const = 0; //求队长

    virtual void enQueue(const T &x) = 0; //入队

    virtual T deQueue() = 0; //出队

    virtual T getHead() const = 0; //获取队头

    virtual ~Queue(){} //虚析构
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

#endif //QUEUE_H
