#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>

using namespace std;

vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
	vector<vector<string> > ret(0);
    int i = 0 , se = 0, len = start.length(), runlen = 0;
	unordered_map<string, int> m[2] ;
	unordered_map<string, string> parent ;
	//unordered_set<char> alpha({'a','b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'});
	queue<string> q[2] ;
	string str[2] ;

	str[0] = end ;
	str[1] = start ;

	m[1][start] = 1 ;
	m[0][end] = 1 ;

	q[1].push(start) ;
	q[0].push(end) ;
	while(1){
		string ref ;
		se = ! se ;
		if(q[se].empty()){
			break;
		}
		ref = q[se].front() ;
			
		for(i = 0; i < len; i++){
			char c ;
			//unordered_set<char> a (alpha) ;
			//a.erase(ref[i]) ;
			for( c = 'a'; c <= 'z'; c++){
				if(c == ref[i]){continue;}
				string temp (ref) ;
				temp[i] = c ;
				if(m[!se][temp] > 0){
					int newrunlen = m[se][q[se].front()] + m[!se][temp] ;
					if(newrunlen == runlen || runlen == 0  ){
						vector<string> transformation ;
						stack<string> start ;
						queue<string> end ;
						runlen = newrunlen ;
						string str (q[se].front()) ;
						while(str.length() == len ){
							if(se == 1){
								start.push(str) ;
							}else{
								end.push(str);
							}
							str = parent[str] ;
						}
						str = temp ;
						while(str.length() == len){
							if(se == 1){
								end.push(str) ;
							}else{
								start.push(str) ;
							}
							str = parent[str] ;
						}
						while(!start.empty()){
							transformation.push_back(start.top()) ;
							start.pop() ;
						}
						while(!end.empty()){
							transformation.push_back(end.front()) ;
							end.pop() ;
						}
						ret.push_back(transformation);
					}else{
						return ret ;
					}
				}
				if(dict.find(temp) != dict.end()){
					dict.erase(temp);
					q[se].push(temp) ;
					m[se][temp] = m[se][q[se].front()] + 1;					
					parent[temp] = q[se].front() ;
				}
			}
		}
		m[se][q[se].front()] = 0 ;
		q[se].pop(); 
	}
	return ret ;
}
int main(){
	string s("hot") ;
	string e("dog") ;
	unordered_set<string> d({"hot","dog","dot"});
	vector<vector<string> > ret = findLadders(s, e, d);
	for(int i = ret.size(); i > 0; i--){
		for(int j = ret[i - 1].size(); j> 0; j--){
			cout << ' ' <<  ret[i - 1][j - 1] ;
		}
		cout << '\n' ;
	}
	return 0;
}
