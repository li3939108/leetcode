#include <iostream>
#include <vector>

using namespace std ;
bool dfs(vector<vector<char> > &board, vector<vector<bool> > &visited, int i, int j, string word){
	int jl = board[0].size(), il = board.size();
	if(word.length() == 0){
		return true ;
	}else if(i >= il || j >= jl || i < 0 || j < 0){
		return false ;
	}else if(visited[i][j]){
		return false ;		
	}else if(board[i][j] == word[0]){
		visited[i][j] = true;
		if(	dfs(board, visited, i + 1, j, word.substr(1)) ||
			dfs(board, visited, i, j + 1, word.substr(1)) ||
			dfs(board, visited, i - 1, j, word.substr(1)) ||
			dfs(board, visited, i, j - 1, word.substr(1)) ){
			return true ;
		}else{
			visited[i][j] = false ;
			return false ;
		}
	}else{
		return false ;
	}

}
bool exist(vector<vector<char> > &board, string word) {
	int i, j ;
	int jl = board[0].size(), il = board.size();
	vector<bool> sample(jl) ;
	vector<vector<bool> > visited(il, sample) ;
	for(i = 0; i< il; i++){
		for(j = 0; j < jl; j++){
			if(dfs(board, visited, i, j, word) ){
				return true ;
			}
		}
	}
//	return false ;
}
int main(){
	vector<vector<char> > board(0) ;
	vector<char> str1 ({'a'}) ;
	vector<char> str2 ({'s', 'f', 'c', 's'}) ;
	vector<char> str3 ({'a', 'd', 'e', 'e'}) ;
	board.push_back (str1) ;
	//board.push_back (str2) ;
	//board.push_back (str3) ;
	cout << "result: " << exist(board, "ab") << '\n' ;
}
