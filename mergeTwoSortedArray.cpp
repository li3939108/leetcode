// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

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

