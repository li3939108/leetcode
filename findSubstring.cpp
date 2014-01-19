#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> findSubstring(string S, vector<string> &L) {
        vector<int> index (0) ;
        int size = L.size(), length ;
        if(size  == 0){ 
        }else{
                int i , window, j, l;
                vector<string>::iterator iter; 
                unordered_map<string, int> count ;
                length = L.begin()->length() ;
                for(iter = L.begin(); iter != L.end(); iter++){
                        count[*iter] += 1 ; 
                }   
                window = (int)length * (int)size ;
                l  =  (int)S.length() ;
                for(i = 0; i <= l - window; i++){
                		bool bl = true;
                        unordered_map<string, int> countc(count) ;
                        for(j = i; j < window + i; j = j + length){
                                string sub = S.substr(j, length) ;
                                countc [sub] -= 1;
                                if(countc[sub] < 0){ 
                                	bl = false ;
                                	break;
                                }   
                        }   
                        if(bl) {
                    		index.push_back(i) ;                           
                        }
                        
                }   
        }   
        return index ;
}
int main(){
	int i ;
	string S ("barfoothefoobarman") ;
	vector<string> L ;
	vector<int>  result ;
	L.push_back("bar");
	L.push_back( "foo") ;
	//L.push_back("ba") ;
	cout << "result:\n" ;
	result = findSubstring(S, L) ;
	for(i = 0; i < result.size(); i++){
		cout << ' ' << result[i] ;
	}
	cout << '\n' ;
}