#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int longestValidParentheses(string s) {
    int i, max = 0;
	stack<char> stk ;
	char c;
	vector<int>  m(s.length(), 0);
	vector<int>::iterator iter ;
	for(i = 0; i < s.length(); i++){
		switch(c = s.at(i)){
			case '(':
			stk.push(c);
			break;

			case ')':
			if(stk.empty()){
				stk.push(c);
			}else{
				if(stk.top() == '(' ){
					stk.pop();
					m[stk.size()] += 2 + m[stk.size() + 1] ;
					m[stk.size() + 1] = 0 ;
				}else{
					stk.push(c) ;
				}
			}
			break;
		}
	}
    return m.size() == 0 ? 0 : *max_element(m.begin(), m.end()) ;
}
int main(){
	string test ("(()())))(((((()))))))))))((") ;
	cout << "testcase: " << test << "\nresult: " << longestValidParentheses(test) << '\n' ;
	return 0;
}