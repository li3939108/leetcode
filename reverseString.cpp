#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

void reverseWords(string &s) {
    stack<string> str_s;
    string str;
    int i;
    int state = -1 ;
    string r;
    if(s.empty()){
    	return ;
    }
    for(i = 0; i < s.length(); i++){
            switch(s.at(i)){
                case ' ':
                if(state == 1){
                    string snew(str);
                    str_s.push(snew);
                }
                state = 2;
                break;
                
                default:
                if(state == 2){
                    str.resize(0) ;
                    str.append(1, s.at(i));
                }else if(state == 1|| state == -1){
                    str.append(1, s.at(i)) ;
                }
                state = 1;
                break;
            }
    }
    if(  s.at(s.length() - 1) != ' '){
	    str_s.push(str);
    }
    while( !str_s.empty() ){
        string str_new = str_s.top() ;
        str_s.pop();
        r.append(str_new) ;
        r.append(1,' ') ;
    }
    if(r.empty()){
    	return ;
    }
    r.resize(r.length() - 1);
    s.resize(0);
    s.append(r);
    cout << "\""<< s << "\"" ;
}
int main(){
	string s("  ");
	reverseWords(s) ;
}