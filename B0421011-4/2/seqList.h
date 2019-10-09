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
    int curLength;//当前顺序表中存储的元素个数
    int maxSize;//顺序表的最大长度

    /**
     * 表满时扩大表空间
     */
    void resize() {
        T *p = data; //p指针指向原数组
        maxSize * 2; //空间容量*2
        data = new T[maxSize]; //创建新容量数组
        for (int i = 0; i < curLength; ++i)
            data[i] = p[i]; //将原数组数据拷贝到新数组
        delete[] p; //删除旧的数组
    };

public:
    /**
     * 构造，要分配的数组容量为参数
     * 
     * @param initSize 容量
     */
    seqList(int initSize = 10) {
        if (initSize <= 0) throw badSize(); //检查参数是否合法
        maxSize = initSize; //设定最大容量
        data = new T[maxSize]; //内存分配数组空间
        curLength = 0; //当前长度归零
    }

    /**
     * 拷贝构造，拷贝一个顺序表
     * 
     * @param sList 旧顺序表
     */
    seqList(seqList &sList) {
        maxSize = sList.maxSize; //设置最大容量
        curLength = sList.curLength; //设置当前长度
        data = new T[maxSize]; //内存分配新数组空间
        for (int i = 0; i < maxSize; ++i) {
            data[i] = sList[i]; //拷贝数据
        }
    }

    /**
     * 析构
     */
    ~seqList() {
        delete[] data; //删除数组
    }

    /**
     * 清空表
     */
    void clear() {
        curLength = 0; //长度归零
    }

    /**
     * 判断表是否为空
     */
    bool empty() const {
        return curLength == 0;
    }

    /**
     * 返回顺序表中当前储存元素的个数
     */
    int size() const {
        return curLength;
    }
    
    /**
     * 遍历表，输出所有元素
     */
    void traverse() const {
        if (empty()) cout << "List Empty" << endl;
        else {
            cout << "Traverse seqList" << endl;
            for (int i = 0; i < curLength; i++) {
                cout << data[i] << "  ";
            }
            cout << endl;
        }
    }

    /**
     * 转置表
     */
    void inverse() {
        T tmp; //元素的temp
        for (int i = 0; i < curLength / 2; i++) { //交换元素
            tmp = data[i];
            data[i] = data[curLength - i - 1];
            data[curLength - i - 1] = tmp;
        }
    }

    /**
     * 在位序i处插入值为value的元素，表长加一
     * 
     * @param i 将要插入的index
     * @param value 插入元素
     */
    void insert(int i, const T &value) {
        if (i < 0 || i > curLength) //检查插入范围是否合法
            throw outOfRange();
        if (curLength == maxSize) //检查容量是否足够插入
            resize();
        for (int j = curLength; j > i; j--) //从后向前遍历至将插入的位序i
            data[j] = data[j - 1]; //将元素复制到后一空间
        data[i] = value; //value赋值给目的元素
        ++curLength; //长度加一
    };

    /**
     * 删除元素
     * 
     * @param i 要删除的元素的index
     */
    void remove(int i) {
        if (i < 0 || i > curLength - 1) //检查插入范围是否合法
            throw outOfRange();
        for (int j = i; j < curLength - 1; j++) //从前向后遍历至表尾
            data[j] = data[j + 1]; //将后一个元素的值赋给前一个元素
        --curLength; //长度减一
    }
    
    /**
     * 搜索元素
     * 
     * @param value 传入元素
     * @return index 返回首一个与该元素相等的index，查找失败返回-1
     */
    int search(const T &value) const {
        for (int i = 0; i < curLength; i++) {
            if (value == data[i])
                return i;
        }
        return -1;
    };

    /**
     * 访问位序为i的元素的值
     * @param i 要访问的元素的index
     */
    T visit(int i) const {
        return data[i];
    };
};

#endif //LIST_SEQLIST_H
