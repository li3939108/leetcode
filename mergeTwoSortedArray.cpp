/*
Given two sorted integer arrays A and B, merge B into A as one sorted array.

Note:
You may assume that A has enough space to hold additional elements from B. The number of elements initialized in A and B are m and n respectively.
*/

#include "stdafx.h"
#include <iostream>

using namespace std;

void merge(int A[], int m, int B[], int n) {
	int bi = n - 1, ai = m - 1;
	while(bi >= 0 || ai >= 0){
		if(ai >= 0 && (bi < 0 || B[bi] < A[ai])){
			A[ai + bi + 1] = A[ai] ;
			ai -= 1;
		}else{
			A[ai + bi + 1] = B[bi] ;
			bi -= 1;
		}
	}
}
int _tmain(int argc, _TCHAR* argv[]){
	return 0;
}

