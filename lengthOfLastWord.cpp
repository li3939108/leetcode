#include <iostream>

int lengthOfLastWord(const char *s) {
	int p = 0, i = 0, length = 0 ;
	while(s[i] != 0){
	if(s[i] == ' '){
		length = i - p == 0 ? length : i - p ;
		p = i + 1;
	}
	i++;
	}
	return i - p == 0 ? length : i - p;
}
