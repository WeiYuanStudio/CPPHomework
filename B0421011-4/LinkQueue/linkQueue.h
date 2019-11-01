#ifndef LINKQUEUE_H
#define LINKQUEUE_H

#include "Queue.h"

template <class T>
class linkQueue : public Queue<T> {
private:
    struct Node {
        T data; //数据
        Node *next; //下一个元素

        Node(const T &x, Node *N = nullptr) {
            data = x;
            next = N;
        }

        Node(Node *p = nullptr) {
            next = p;
        }

        ~Node() {}
    };

    Node *front; //队头指针
    Node *rear; //队尾指针
public:
    /**
     * 构造
     */
    linkQueue() {
        front = rear = nullptr; //初始化头、尾指针为空
    }

    /**
     * 析构
     */
    ~linkQueue() { clear(); }; //析构

    /**
     * 清除队列
     */
    void clear() {
        Node *p;
        while (front != nullptr) {
            p = front; //暂存头指针所指元素
            front = front->next; //头指针后移
            delete p; //删除暂存指向元素
        }
        rear = nullptr; //尾指针置空
    }

    /**
     * 判空
     */
    bool empty() const {
        return front == nullptr; //判断头指针是否空
    }

    /**
     * 取长度
     */
    int size() const {
        Node *p = front;
        int count = 0;
        while (p) {
            count++;
            p = p->next;
        }
        return count;
    }

    /**
     * 入队
     */
    void enQueue(const T &x) {
        if (rear == nullptr) {
            //原队列为空
            front = rear = new Node(x);
        } else{
            rear->next = new Node(x); //队尾后一个元素指针指向新元素
            rear = rear->next; //队尾指针后移
        }
    }

    /**
     * 出队
     */
    T deQueue() {
        if (empty())
            throw outOfRange();
        Node *p = front;
        T value = front->data; //取队头元素
        front = front->next; //指针后移
        if (front == nullptr)//队列最后一个元素被取出，队尾为null
            rear = nullptr; //队尾指针置空
        delete p; //当前元素删除
        return value; //返回元素
    }

    /**
     * 获取头元素
     */
    T getHead() const {
        if (empty())
            throw outOfRange();
        return front->data;
    }
};

#endif //LINKQUEUE_H
