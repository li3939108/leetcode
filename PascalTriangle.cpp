/*
Given an index k, return the kth row of the Pascal's triangle.

For example, given k = 3,
Return [1,3,3,1].

Note:
Could you optimize your algorithm to use only O(k) extra space?
*/
#include <iostream>
#include <vector>

using namespace std ;
vector<int> getRow(int rowIndex) {
	vector<int> ret(1, 1) ;
	int i, j;
	for(i = 0; i <= rowIndex; i++){
		vector<int> newret (0);
		for(j = 0; j < i + 1; j++){
			if(j - 1 < 0){
				newret.push_back(ret[j])  ;
			}else if( j == i){
				newret.push_back(ret[j - 1])  ;
			}else{
				newret.push_back(ret[j] + ret[j - 1]);
			}
		}
		ret = newret ;
	}
	return ret ;
}
int main(){
	int index = 7, i;
	vector<int> v = getRow(index);
	cout << "index: " <<  index << '\n' ;
	cout << "result:"  ;

	for(i = 0; i < v.size(); i++){
		cout << ' ' <<  v[i] ;
	}
	cout << '\n' ;
}
