//
// Created by Adam on 2019/10/3.
//

#ifndef LIST_LINKLIST_H
#define LIST_LINKLIST_H

#include <iostream>
#include "List.h"

template<class T>
class linkList : public List<T> {
private:
    struct Node { //节点结构
        T data; //数据
        Node *next; //后继指针
        Node(const T value, Node *p = NULL) {
            data = value;
            next = p;
        }

        Node(Node *p = NULL) {
            next = p;
        }
    };

    Node *head; //链表头指针
    Node *tail; //链表尾指针
    int curLength; //链表长度
    Node *getPosition(int i) const {
        if (i < -1 || i > curLength - 1) {
            return NULL;
        }
        Node *p = head;
        int count = 0;
        while (count <= i) {
            p = p->next;
            ++count;
        }
        return p;
    }; //返回指向i位序节点的指针
public:
    linkList() {
        tail = head = new Node();
        curLength = 0;
    };

    ~linkList() {
        clear();
        delete head;
    };

    void clear() override {
        Node *p, *tmp;
        p = head->next;
        while (p != NULL) {
            tmp = p;
            p = p->next;
            delete tmp;
        }
        head->next = NULL;
        tail = head;
        curLength = 0;
    }

    bool empty() const override {
        return curLength == 0;
    }

    int size() const override {
        return curLength;
    }

    int prior(const T &value) const {

    }

    void insert(int i, const T &value) override { //插入
        Node *p, *q;
        if (i < 0 || i > curLength) throw outOfRange();
        p = getPosition(i - 1); //求该位序的前驱
        q = new Node(value, p->next);
        p->next = q;
        if (p == tail) tail = q;
        ++curLength;
    }

    void remove(int i) override {

    }

    int search(const T &value) const override { //搜索元素位序
        Node *p = head->next;
        int count = 0;
        while (p != NULL) {
            if (p->data == value) return count;
            p = p->next;
            ++count;
        }
        return -1;
    }

    int prior(const T &value) {
        Node *p = head->next;
        Node *pre = NULL;
        int count = -1;
        while (p != NULL) {
            if (p->data == value) {
                return count;
            }
            p = p->next;
        }
        return -1;
    }

    T visit(int index) const override { //通过位序访问元素
        Node *p = head->next;//工作指针
        for (int i = 0; i < index; ++i) {
            p = p->next;
        }
        return p->data;
    }

    void traverse() const override { //遍历表
        Node *p = head->next;
        while (p != NULL) {
            cout << p->data << " ";
            p = p->next;
        }
    }

    void inverse() override { //转置表

    }
};

#endif //LIST_LINKLIST_H
