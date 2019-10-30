#include<iostream>
#include "Num.cpp"

using namespace std;

int main() {
    cout << "Please input a number" << endl;
    int x; //用于存放输入数据
    cin >> x; //标准输入流读取x

    Num num(x);
    num.showDecimal(); //显示十进制数
    num.showBinary(); //显示二进制数
}
