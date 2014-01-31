#include <iostream>
#include <vector>
#include <map>

using namespace std;

//Time Complexity O(MN) 
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
	    vector<int> dpv (dp[i].begin(), dp[i].end()) ;
		if(max < largestRectangleArea(dp[i])){
		    max = largestRectangleArea(dp[i]);
		}
	}
	return max ;
}
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