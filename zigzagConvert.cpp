#include <iostream>
#include <string>

using namespace std;

string convert(string s, int nRows) {
	string line[nRows], ret;
	int i , l, d = nRows - 1;
	for(i = 0; i<s.length(); i++){
		if((i / d) % 2 == 1){
			l = d - (i % d) ;
		}else{
			l = i % d;
		}
		line[l].push_back ( s[i]) ;
	}
	for(i = 0; i< nRows; i++){
		ret.append(line[i]) ;
	}
	return ret;
}
int main(){
	string test ("PAYPALISHIRING");
	cout << "testcase: " << test << "\nresult: " << convert(test, 3) << '\n' ;
	return 0;
}