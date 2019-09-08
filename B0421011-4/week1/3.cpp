#include<iostream>
using namespace std;

/*
3、	公元前五世纪，我国古代数学家张丘建在《算经》一书中提出了"百鸡问题"：鸡翁一值钱五，鸡母一值钱三，鸡雏三值钱一
	百钱买百鸡，问鸡翁、鸡母、鸡雏各几何？请设计一个"高效"的算法求解
*/

int main() {
	int money = 100;
	int fatherNum, motherNum, threeSonNum;
	int fatherPrice = 5;
	int motherPrice = 3;
	double threeSonPrice = 1;
	
	for(int fatherNum = 0; fatherNum <= money / fatherPrice; fatherNum++) {
		for(int motherNum = 0; motherNum <= money / motherPrice; motherNum++){
			for(int threeSonNum = 0; threeSonNum <= money / threeSonPrice; threeSonNum++) {
				if(fatherNum + motherNum + threeSonNum * 3 == 100 && fatherPrice * fatherNum + motherPrice * motherNum + threeSonPrice * threeSonNum == 100)
					cout << "Father Num: " << fatherNum << " Mother Num: " << motherNum << " Son Num: " <<  threeSonNum * 3 << endl;
			}
		}
	}
}
