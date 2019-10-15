#include<iostream>
using namespace std;

int num[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

bool hasNum[10] = {true, true, true, true, true, true, true, true, true, true,}; //记录数组内元素是否已经出列

int count = 1; //碰到未出列的元素+1计数器

int outNum = 0;

int main () {
	while(outNum < 10) {
		for(int i = 0; i < 10; i++) {
			if(hasNum[i]) {
				if(!(count%3)) {
					cout << num[i] << " ";
					hasNum[i] = false;
					outNum ++;
				}
				count ++;
			}
		}
	}
}