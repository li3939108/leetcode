// ConsoleApplication1.cpp : Defines the entry point for the console application.
//
// For use with Visual Studio
/*
Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.


Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].


The largest rectangle is shown in the shaded area, which has area = 10 unit.

For example,
Given height = [2,1,5,6,2,3],
return 10.
*/
#include "stdafx.h"
#include <iostream>
#include <vector>
#include <stack>

using namespace std ;

int largestRectangleArea(vector<int> &height) {
	stack<int> pos ;
	int i = 0, max = 0;
	while(i < height.size() || !pos.empty()){
		int topPos = pos.empty() ? -1 : pos.top() ;
		if(i < height.size() && (pos.empty() || height[topPos] < height[i] )){
			pos.push(i) ;
			i ++ ;
		}else{
			int temp = 0 ;
			pos.pop() ;
			temp = height[topPos] * (pos.empty() ? i : i - pos.top() - 1) ;
			max = (temp > max ? temp : max) ;
		}
	}
	return max ;
}

int main(int argc, char *argv[])
{
	vector<int> hist(0) ;
	hist.push_back(4);
	hist.push_back(2);
	cout << "result: " << largestRectangleArea(hist) << '\n' ;
	while(1) ;
	return 0;
}
