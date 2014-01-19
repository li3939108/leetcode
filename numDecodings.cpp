#include <iostream>
#include <string>
#include <map>
using namespace std;

map<string, int> cache ;
int recursive(string s){
    char c;

    if(s.length() > 0){
        c = s[0] ;
    }else{
        return 1;
    }
    if(c == '0'){
        return 0;
    }else{
        string sub(s.substr(1,s.length())) ;
        int first ;
        int second = 0;
        if(s.length() > 0){
            if(cache[sub] > 0) {
                first = cache[sub] - 1;
            }else{
                first =  recursive(sub)  ;
                cache[sub] = first + 1 ;
            }
        }
        switch(c){
            
            case '1':
            if(s.length()>1 ){
                string sub(s.substr(2,s.length() - 2)) ;    
                if(cache[sub] > 0){
                    second = cache[sub] - 1;
                }else{
                    second = recursive(sub) ;
                    cache[sub] = second + 1;
                }
            }
            
            break ;
            
            case '2':
            if(s.length()>1 && s[1] >= '0' && s[1] <= '6'){
                string sub(s.substr(2,s.length() - 2)) ;
                if(cache[sub] > 0){
                    second = cache [sub] - 1;
                }else{
                    second = recursive(sub );
                    cache[sub] = second + 1 ;
                }
            }
            break;
            
        }
        return first + second ;
    }
}
int numDecodings(string s) {
    if(s.length() > 0){
        return recursive(s) ;
    }else{
        return 0;
    }
    
}

int main(){
    string s("9371597631128776948387197132267188677349946742344217846154932859125134924241649584251978418763151253") ;
    string sss("sss") ;
    cout << "result: \n" ;
    cout << ' ' << numDecodings(s) << '\n' << sss.substr(3,0).length() << '\n';
    return 0;
}