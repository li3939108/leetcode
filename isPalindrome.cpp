#include <iostream>
#include <string>
#include <cctype>

using namespace std;
 
bool isPalindrome(string s) {
	int start=0,e=s.length() - 1;
	while (e >  start){
		if(!isalnum(s.at(e))){
			e -- ;
			continue;
		}
		if(! isalnum(s.at(start))){
			start ++ ;
			continue ;
		}
		if(s.at(start) == s.at(e) || s.at(start) - s.at(e) == 0x20 ||s.at(e) - s.at(start) == 0x20 ){
			e--;
			start++;
			continue;
		}else{
			return false;
		}
	}
	return true;

}
int main(){
	string test ("race a car");
	cout << "testcase: " << test << "\nresult: " << isPalindrome(test) << '\n';
	return 0;
}