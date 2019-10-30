#include <iostream>
#include "Num.h"

using namespace std;

/**
 * 构造方法
 */
Num::Num(int num) {
    // this->num = num; //设置数字字段

    //设置符号位
    if(num < 0) { //当数字小于零，符号位为1
        this->sign = 1;
        this->num = -num; //设置数字字段
    } else { //当数字不小于零，符号位为0
        this->sign = 0;
        this->num = num; //设置数字字段
    }
}

/**
 * 压栈二进制数
 */
void Num::countBinary() {
    int tmp = num; //拷贝原数据
    int count = 0; //设置计数

    //开始反复求余自除取得各位二进制进行压栈
    do {
        binaryStack.push(tmp % 2); //取余压栈
        tmp = tmp / 2; //退位
        ++count;
    } while (tmp > 1); //达到最后一位退出

    binaryStack.push(tmp); //压栈最后一位

    //压完栈空位填零
    for (int i = 1; i < 7 - count; ++i) {
        binaryStack.push(0);
    }

    binaryStack.push(sign); //压栈符号位
}

/**
 * 出栈显示二进制数
 */
void Num::showBinary() {
    countBinary(); //对原数据进行压栈
    
    cout
        << "\n  8 BIT BINARY: \n"
        << " - - - - - - - - \n|";

    while(!binaryStack.empty()) {
        cout << binaryStack.pop() << "|";
    }

    cout << "\n - - - - - - - - " << endl; 
}

/**
 * 显示十进制数
 */
void Num::showDecimal() {
    cout << "Input num : ";
    cout << num << endl;
}
