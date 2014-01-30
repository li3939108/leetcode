#include <iostream>
#include <vector>
#include <map>

using namespace std;

//Time Complexity O(maxHeight * MN) 
int maximalRectangle(vector<vector<char> > &matrix) {
	int il = matrix.size(), jl, i, j, max = 0, maxColumn = 0;
	vector<vector<int> > dp(0) ;
	vector<int> sample(0) ;
	if(il == 0){
		return 0 ;
	}else{
		jl = matrix[0].size() ;
		sample.assign(jl, 0) ;
		dp.assign(il, sample);
	}
	for(i = 0; i < il; i++){
		for(j = 0; j < jl; j++){
			if(matrix[i][j] == '1'){
				if(i != 0){
					dp[i][j] = dp[i - 1][j] + 1;
				}else{
					dp[i][j] = 1 ;
				}
				if(dp[i][j] > maxColumn ) {
					maxColumn = dp[i][j] ;
				}
			}
		}
	}
	for(i = 0; i < il; i++){
		vector<int> lineMax (maxColumn + 1, 0);
		vector<int> lineT(lineMax) ;
		for(j = 0; j < jl; j++){
			int k ;
			for(k = 1; k <= maxColumn; k++){
				if(k > dp[i][j]){
					lineT[k] = 0 ;
				}else{
					lineT[k] += k ;
					if(lineT[k] > lineMax[k]){
						lineMax[k] = lineT[k] ;
					}
				}
				if(lineMax[k] > max){
					max = lineMax[k] ;
				}
			}

		}
	}
	return max ;
}