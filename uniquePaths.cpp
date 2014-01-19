#include <iostream>

int uniquePaths(int m, int n) {
	int a[m][n] , i, j;    
	for(i = 0; i < m; i++){
		a[i][0] = 1 ;
	}
	for(j = 0; j < n; j++){
		a[0][j] = 1 ;
	}
	for(i = 1; i < m; i++){
		for(j = 1; j < n; j++){
			a[i][j] = a[i - 1][j] + a[i][j - 1] ;
		}
	}
	return a[m - 1][n - 1] ;
}
int main(){
}
