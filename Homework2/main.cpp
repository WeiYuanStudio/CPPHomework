#include <iostream>
using namespace std;

/**
 * @author 04181010 魏源
 * @version 1.0
 * @since g++ (GCC) 8.2.1 20181127 Copyright © 2018 Free Software Foundation, Inc.
 * @return
 */

int main() {
    cout << "请输入序号回车选择你的目的地" << endl
    << "1.广东" << endl
    << "2.江苏" << endl
    << "3.四川" << endl
    << "4.西藏" << endl;
    int target;
    cin >> target;
    cout << "请输入快件重量 / Kg" << endl;
    int weight;
    cin >> weight;
    int price;
    switch (target) {
        case 1:
            if(weight <= 1)
                price = 6;
            else {
                price = 6 + 1 * (weight - 1);
            }
            break;
        case 2:
            if(weight <= 1)
                price = 10;
            else {
                price = 10 + 8 * (weight - 1);
            }
            break;
        case 3:
            if(weight <= 1)
                price = 15;
            else {
                price = 15 + 12 * (weight - 1);
            }
            break;
        case 4:
            if(weight <= 1)
                price = 22;
            else {
                price = 22 + 18 * (weight - 1);
            }
            break;
    }
    cout << "价格是" << price << endl;
}
