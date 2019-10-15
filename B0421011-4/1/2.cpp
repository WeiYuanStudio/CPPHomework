#include<iostream>
using namespace std;

/*
2、	在数组A[n]中查找值为k的元素，
	若找到则输出其位置i(1≤i≤n)，否则输出0作为标志
	设计算法求解此问题，并分析其时间复杂度

答：
    时间复杂度为O(n)
*/ 

/****    Test Case Start    ****/

int nums[] = {56, 46, 91, 43, 23, 65};

int target = 23;

/****    Test Case End     ****/

void sort(int*, int);

int search(int, int*, int);

void printNums(int* ,int); 

int main() {
	printNums(nums, sizeof(nums)/sizeof(int)); 
	cout << "Searching Target:" << target << endl;
	cout << "Target Index Found:" << search(target, nums, sizeof(nums)/sizeof(int)) + 1;
}

int search(int target, int* nums, int length) {
	for(int i = 0; i < length; i++) {
		if(target == nums[i]){
			return i;
		}
	}
	return -1;
}

void printNums(int* nums, int length) {
	for(int i = 0; i < length ; i++) {
		cout << nums[i] << "   ";
	} 
	
	cout << endl;
}