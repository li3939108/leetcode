#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std ;

void solveSudoku(vector<vector<char> > &board) {
	queue<int> unresolved ;
	int i, j, k  ;

	/*initialization*/
	unordered_set<char>	h[9], v[9], g[9] ;
	for(i = 0; i < 9; i++){
		h[i].insert({'1', '2', '3', '4', '5', '6', '7', '8', '9'}) ;
		v[i].insert({'1', '2', '3', '4', '5', '6', '7', '8', '9'}) ;
		g[i].insert({'1', '2', '3', '4', '5', '6', '7', '8', '9'}) ;
	}
	for(i = 0; i < 9; i++){
		for(j = 0; j < 9; j++){
			if(board[i][j] != '.'){
				unresolved.push(i * 9 + j) ;
			}else{
				char c = board[i][j]
				h[i].erase(c);
				v[j].erase(c);
				g[(i / 3) * 3 + j / 3 ].erase(c) ;
			}
		}
	}
	k = unresolved.size() ;
	while(1){
		if(unresolved.size() == 0){
			return ;
		}else if(k == 0){
			cout << "no answer\n" ;
			return ;
		}
		i = unresolved.top() / 9;
		j = unresolved.top() % 9 ;
		unresolved.pop();
		
		
		
	}
}
int main(){
}
