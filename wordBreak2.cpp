#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;


void backtracking(vector<vector<bool> > &dp, int loc, string si, string &s, vector<string> &sv){
     if(loc == 0){
         sv.push_back(si);
     }else{
         for(int i = 0; i < loc; i++){
             if(dp[i][loc]){
                backtracking(dp, i, s.substr(i, loc - i) + " " + si, s, sv) ;
             }
         }
     }
}

vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
    vector<string> ret(0) ;
    int len = s.length(), max_dict_length = 0;
    vector<bool> space_loc(len+1, false);
    vector<vector<bool> > dp(len, vector<bool>(len + 1, false) );
    space_loc[0] = true;
    for(auto iter = wordDict.begin(); iter != wordDict.end(); iter++){
        max_dict_length = max_dict_length < iter->length() ? iter->length() : max_dict_length;
    }
    for(int i = 0 ; i < len ; i ++){
        if(space_loc[i] ){
            for(int j = i + 1; j < len + 1 && j - i <= max_dict_length  ; j++){        
                if(wordDict.find(s.substr(i, j - i) ) != wordDict.end() ) {
                    space_loc[j] = true;
                    dp[i][j] = true;
                }
            }
            
        }
    }
    for(int i = 0; i < len; i++){
        if(dp[i][len] ){
            backtracking(dp, i, s.substr(i, len - i), s, ret);
        }
    }
    return ret;
}

int main(){
	string s("catsanddog");
	unordered_set<string> dict = {"cat","cats","and","sand","dog"} ;
	vector<string> bk = wordBreak(s, dict);
	for(auto iter = bk.begin(); iter != bk.end() ; iter ++){
		cout << *iter << endl ;
	}
}
