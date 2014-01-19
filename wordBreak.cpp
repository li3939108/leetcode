#include <iostream>
#include <string>
#include <unordered_set>
#include <map>

using namespace std;

bool wordBreak(string s, unordered_set<string> &dict) {
    unordered_set<string>::iterator iter;
    int i ;
    unordered_set<string> dc(dict);
    map<string, bool> m ;
    map<string, bool>::iterator mit ;
    if(s.length() == 0){
        return false ;
    }
    for(i = 0;; i++){
        for(iter = dc.begin(); iter != dc.end(); iter ++ ){
            if(i < iter->length()){
                if(i == s.length()){
                    m[*iter] = true;
                }else if(iter->at(i) != s.at(i)){
                    m[*iter] = true;
                }
            }else{
                if(i == s.length()){
                    return true;
                }else{
                    if(wordBreak(s.substr(i, s.length() - i), dict)){
                        return true;
                    }else{
                        m[*iter] = true;
                    }
                }
            }
        }
        for(mit = m.begin(); mit != m.end(); mit ++){
            if(mit->second == true){
                dc.erase(mit->first) ;
            }
        }
        if(dc.empty()){return false;}
    }
}

int main(){
    string test("saaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
    unordered_set<string> dict;
    dict.insert("a");
    //dict.insert("leetcode");
    dict.insert("aa");
    dict.insert("aaa");
    dict.insert("aaaa");
    cout << ' ' << wordBreak(test, dict) << '\n' ;
    return 0;
}
