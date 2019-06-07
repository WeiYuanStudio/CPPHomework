#include <iostream>
using namespace std;

bool Test(int num) {
    int D1 = num % 10;
    num -= D1;
    int D2 = num % 100 / 10;
    num -= D2;
    int D3 = num % 1000 / 100;
    num -= D3;
    int D4 = num % 10000 / 1000;
    num -= D4;
    int D5 = num % 100000 / 10000;
    num -= D5;
    int D6 = num % 1000000 / 100000;
    if (D1 == D6 && D2 == D5 && D3 == D4)
        return true;
    else
        return false;
}

int main() {
    for (int i = 111111; i <= 999999; i++) {
        if(Test(i)) {
            cout << i << endl;
        }
    }
}
