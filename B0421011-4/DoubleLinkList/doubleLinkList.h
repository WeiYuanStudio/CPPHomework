//
// Created by Adam on 2019/9/28.
//

#ifndef LIST_DOUBLELINKLIST_H
#define LIST_DOUBLELINKLIST_H

#include "List.h"
#include <iostream>

template<class T>
class doubleLinkList : List<T> {
private:
    struct Node{
        Node *prior;
        T data;
        Node *next;
        Node(const T &value, Node *p = nullptr, Node *n = nullptr) {
            data = value;
            prior = p;
            next = n;
        }
        Node() : next(NULL), prior(NULL){}
        ~Node(){}
    };
    Node *head, *tail;
    int curLength;
public:
    /**
     * 无参构造
     */
    doubleLinkList() {
        head = new Node();
        tail = new Node();
        head->next = tail;
        tail->prior = head;        
        curLength = 0;
    }

    /**
     * 清空
     */
    void clear() override{
        Node *p = head->next, *tmp;
        head->next = tail;
        tail->prior =  head;
        while(p != tail) {
            tmp = p->next;
            delete p;
            p = tmp;
        }
        curLength = 0;
    }

    /**
     * 判空
     */
    bool empty() const override{
        return head->next == tail->prior;
    }

    /**
     * 求线性表长度
     */
    int size() const {
        return curLength;
    }

    /**
     * 按照index插入
     */
    void insert(int i, const T &value) override{
        if(i < 0 || i > curLength)
            throw outOfRange();
        Node *p = head->next;
        for (int j = 0; j < i; ++j) {   
            p = p->next;
        }
        Node *tmp = new Node(value, p->prior, p);
        p->prior->next = tmp;
        p->prior = tmp;
        ++curLength;
    }

    /**
     * 移除节点
     */
    void remove(int i) {
        if(i < 0 || i > curLength)
            throw outOfRange();
        Node *p = head->next;
        for (int j = 0; j < i; ++j) {   
            p = p->next;
        }
        p->prior->next = p->next;
        p->next->prior = p->prior;
        delete p;
        --curLength;
    }

    /**
     * 搜索节点
     */
    int search(const T &value) const { //TODO: 修改前两文件中的拼写错误
        Node *p = head->next;
        int count = 0;
        while(p != tail && p->data != value) {
            p = p->next;
            ++count;
        }
        if(p == tail)
            return -1;
        return count;
    }

    /**
     * 访问节点
     */
    T visit(int i) const {}

    /**
     * 遍历双链表
     */
    void traverse() const override{
        Node *p = head->next;
        while(p != tail) {
            cout << p->data << " ";
            p = p->next;
        }
        cout << endl;
    }

    /**
     * 逆置双链表
     */
    void inverse() override {
        Node *tmp, *p;
        p = head->next;
        head->next = tail;
        tail->prior = head;
        while(p != tail) {
            tmp = p->next;
            p->next = head->next;
            p->prior = head;
            head->next->prior = p;
            head->next = p;
            p = tmp;
        }
    }
    ~doubleLinkList() {}
};

#endif //LIST_DOUBLELINKLIST_H