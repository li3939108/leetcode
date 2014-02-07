/*
Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

For example,
Given the following matrix:

[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
You should return [1,2,3,6,9,8,7,4,5].
*/
#include <iostream>
#include <vector>

using namespace std;

vector<int> spiralOrder(vector<vector<int> > &matrix){
	int m=matrix.size(), n ;
	vector<int> ret(0) ;
	if(m > 0){
		n = matrix[0].size() ;
		ret.resize(m * n) ;
		recursive(matrix, m, n, 0, 0, 0, ret) ;
	}
	return ret;
}
void recursive(vector<vector<int> > &matrix, int m, int n, int i, int j, int s, vector<int> &ret){
	int mm = 0, nn = 0;
	if(n <= 0 || m <= 0){
		return ;
	}else if(n == 1){
		for(mm = 0; mm < m; mm ++){
			ret[s + mm] = matrix[i + mm][j] ;
		}
		return ;
	}else if(m == 1){
		for(nn = 0; nn < n; nn ++){
			ret[s + nn] = matrix[i][j + nn] ;
		}
		return ;
	}else {
		for(nn = 0; nn < n - 1; nn ++){
			ret[s + nn] = matrix[i][j + nn] ;
		}
		for(nn = 0; nn < n - 1; nn ++){
			ret[s + n - 1 + m - 1 + nn] = matrix[i + m - 1][j + n - 1 - nn] ;
		}
		for(mm = 0; mm < m - 1; mm ++){
			ret[s + 2 * (n - 1) + m - 1 + mm] = matrix[i + m - 1 - mm][j] ;
		}
		for(mm = 0; mm < m - 1; mm ++){
			ret[s + n - 1 + mm] = matrix[i + mm][j + n - 1] ;
		}
		return recursive(matrix, m - 2, n - 2, i + 1, j + 1, s + 2 * (n - 1) + 2 * (m - 1), ret) ;
	}
}
