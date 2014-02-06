/*
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
*/
#include <iostream>
#include <string>
#include <stack>
#include <map>

using namespace std;

bool isValid(string s) {
	int i;
	stack<char> stk ;
	char c;
	map<char, char> m;
	m['('] =')';
	m['['] = ']';
	m['{'] = '}';
	for(i = 0; i < s.length(); i++){
		switch(c = s.at(i)){
			case '(':
			case '[':
			case '{':
			stk.push(c);
			break;

			case ')':
			case ']':
			case '}':
			if(stk.empty()){
				return false;
			}else{
				if(m[stk.top()] == c){
					stk.pop();
				}else{
					return false;
				}
			}
			break;
		}
	}
	return stk.empty();
}
int main(){
	string test("()[]([]){([])}");
	cout << "testcase: " << test << "\nresult: " << isValid (test) << '\n' ;
	return 0;
}
