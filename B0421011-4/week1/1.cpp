#include<iostream>
using namespace std;

/*
1、	已知输入x，y，z三个不相等的整数，设计一个"高效"算法，使得这三个数按从小到大输出。
	"高效"的含义是用最少的元素比较次数、元素移动次数和输出次数
*/

/****    Test Case Start    ****/

int nums[] = {42, 15, 64, 78, 32, 48}; 

/****    Test Case End     ****/

//冒泡排序 
void sort(int* nums, int length) {
	for(int i = 0; i < length; i++) {
		for(int j = i; j < length; j++) {
			if (nums[j] < nums[i]) {
				int swap = nums[i];
				nums[i] = nums[j];
				nums[j] = swap;
			}
		}
	}
}

//打印数组
void printNums(int* nums, int length) {
	for(int i = 0; i < length ; i++) {
		cout << nums[i] << "   ";
	} 
	cout << endl;
}

int main() {
	printNums(nums, sizeof(nums)/sizeof(int)); 
	sort(nums, sizeof(nums)/sizeof(int));
	printNums(nums, sizeof(nums)/sizeof(int)); 
}