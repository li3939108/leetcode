#include <iostream>
#include <string>
#include <map>

using namespace std ;

string longestPalindrome(string s) {
	int i, j, len = s.length(), max = 1, maxS = 0, maxE = 0;
	if(s.length() == 0){
		return s ;
	}
	for (i = 0; i < len; i ++){
		for(j = 1; ; j ++){
			if(i - j >= 0 && i + j < len){
				if(s[i - j] == s[i + j]){
					continue ;
				}else{
					break;
				}
			}else{
				break;
			}
		}
		if( (j - 1) * 2 + 1 > max){
			max = (j - 1) * 2 + 1;
			maxS = i - j + 1;
			maxE = i + j - 1;
		}
		for(j = 0; ; j++){
			if(i - j >= 0 && i + 1 + j < len){
				if(s[i - j] == s[i + 1 + j]){
					continue ;
				}else{
					break;
				}
			}else{
				break;
			}
		}
		if( j * 2 > max){
			max = j * 2 ;
			maxS = i - j + 1 ;
			maxE = i + j ;
		}
	}
	return s.substr(maxS, maxE - maxS + 1) ;
}

