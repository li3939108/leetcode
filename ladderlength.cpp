#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <queue>

using namespace std;

int ladderLength(string start, string end, unordered_set<string> &dict) {
	int i = 0 , se = 0, len = start.length();
	unordered_map<string, int> m[2] ;
	unordered_set<char> alpha({'a','b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'});
	queue<string> q[2] ;
	string str[2] ;

	str[0] = end ;
	str[1] = start ;

	m[1][start] = 1 ;
	m[0][end] = 1 ;
	q[1].push(start) ;
	q[0].push(end) ;
	while(!(q[1].empty() && q[0].empty())){
		string ref ;
		se = ! se ;
		ref = q[se].front() ;
			
		for(i = 0; i < len; i++){
			unordered_set<char> a (alpha) ;
			a.erase(ref[i]) ;
			for( auto c = a.begin(); c != a.end(); c++){
				string temp (ref) ;
				temp[i] = *c ;
				if(m[!se][temp] > 0){
					return m[se][q[se].front()] + m[!se][temp] ;
				}
				if(dict.find(temp) != dict.end()){
					dict.erase(temp);
					q[se].push(temp) ;
					m[se][temp] = m[se][q[se].front()] + 1;					
				}
			}
		}
		m[se][q[se].front()] = 0 ;
		q[se].pop(); 
	}
	return 0;
}
int main(){
	string s("hot") ;
	string e("dog") ;
	unordered_set<string> d({"hot","dog","dot"});
	cout << ' ' << ladderLength(s, e, d) << '\n';
	return 0;
}
