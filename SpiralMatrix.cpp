/*
Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

For example,
Given n = 3,

You should return the following matrix:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]
*/
#include <iostream>
#include <vector>

using namespace std;

void fill(vector<vector<int> > m, int n, int i, int j, int s){
	if(n <= 0){
		return ;
	}else if(n == 1){
		m[i][j] = s ;
		return ;
	}else {
		int ii ;
		for(ii = 0 ; ii < n - 1; ii++){
			m[i][j + ii] = s + ii ;
			m[i + ii][j + n - 1] = s + n - 1 + ii ;
			m[i + n - 1][j + n - 1 - ii] = s + 2 * (n - 1) + ii ;
			m[i + n - 1 - ii][j] = s + 3 * (n - 1) + ii ;
		}
		fill(m, n - 2, i + 1, j + 1, s + 4 * (n - 1)) ;
		
	}
}
vector<vector<int> > generateMatrix(int n){
	int n2 = n * n, i, j ;
	vector<int> line(n) ;
	vector<vector<int> > ret(n, line) ;
	fill(ret, n, 0, 0, 1) ;
}

int main(){

}
