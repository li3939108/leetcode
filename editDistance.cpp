/*
Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2. (each operation is counted as 1 step.)

You have the following 3 operations permitted on a word:

a) Insert a character
b) Delete a character
c) Replace a character
*/
#include <iostream>
#include <string>

using namespace std; 

int minDistance(string word1, string word2) {
	int d[word1.length() + 1][word2.length() + 1] , i, j;
	for (i = 0; i <= word1.length(); i++){
		d[i][0] = i;
	}
	for (j = 0; j <= word2.length(); j++){
		d[0][j] = j;
	}
	for (i = 1; i <= word1.length(); i++){
		for ( j = 1; j <= word2.length(); j++){
			if(word1[i - 1] == word2[j - 1]){
				d[i][j] = d[i - 1][j - 1] ;
			}else{
				d[i][j] = min(min(d[i - 1][j - 1], d[i][j - 1]), d[i - 1][j]) + 1;
			}
		}
	}
	return d[word1.length()][word2.length()] ;
}
int main(){
	string word1("abcdef"), word2("fabcde") ;
	cout << ' ' << minDistance(word1, word2) << '\n' ;
	return 0 ;
}
