#include <iostream>
#include <string>
#include <vector>

using namespace std;

string longestCommonPrefix(vector<string> &strs) {
	int size = strs.size() ;
	int a[size - 1] ;
	int i ;

	for(i = 0; i < size - 1 ; i++){
		int j, len1 = strs[i].length(), len2 = strs[i + 1].length() ;
		for(j = 0; j < len1 && j < len2 && j < a[i]; j++){
			if(strs[i][j] != strs[i + 1][j]){
				break ;
			}
		}
		a[i + 1] = j ;
	}
	return strs[0].substr(0, a[size - 1]) ;
}
int main(){
	
}