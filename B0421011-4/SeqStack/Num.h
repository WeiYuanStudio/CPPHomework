#ifndef NUM_H
#define NUM_H

#include "Stack.h"
#include "seqStack.h"

class Num {
private:
    int num; //数据
    int sign; //符号位
    seqStack<int> binaryStack; //用于进行二进制操作 //TODO:这里能否解耦，使用Stack
    void countBinary(); //计算二进制
    
public:
    Num(int num); //构造
    void showBinary(); //显示二进制数
    void showDecimal(); //显示十进制数
};

#endif //NUM_H
