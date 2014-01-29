#include <iostream>
#include <vector>

using namespace std ;
int minimumTotal(vector<vector<int> > &triangle) {
	int height = triangle.size(), i, j ;
	for(i = height - 2; i >= 0 ; i --){
		for(j = 0; j < i + 1; j ++){
			triangle[i][j] += min(triangle[i + 1][j], triangle[i + 1][j + 1]) ;
		}
	}
    return triangle[0][0] ;
}
int main(){

}