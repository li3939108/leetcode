/*
Given a string s, partition s such that every substring of the partition is a palindrome.

Return all possible palindrome partitioning of s.

For example, given s = "aab",
Return

  [
    ["aa","b"],
    ["a","a","b"]
  ]
*/
#include <iostream>
#include <string>

using namespace std;

//solve it recursively 
vector<vector<string> > partition(string s) {
	vector<string> sample(0) ;
	vector<vector<string> > ret (0) ;
	int len = s.length() ;
	if(len == 0){
		ret.push_back(sample);
		return ret ;
	}else if(len == 1){
		sample.push_back(s) ;
		ret.push_back(sample) ;
		return ret ;
	}else {
		int i, j ;
		for(i = 1; i <= len; i++){
			if(palindrome(s.substr(0, i))){
				vector<vector<string> > sub ;
				sub = partition (s.substr(i)) ;
				for(auto iter = sub.begin(); iter != sub.end(); iter++){
					vector<string> news (*iter);
					news.insert(news.begin(), s.substr(0, i)) ;
					ret.push_back(news) ;
				}
			}
		}
	}
	return ret ;
}
bool palindrome(string s ) {
	int len = s.length();
	if(len == 0 || len == 1){
		return true;
	}else if(s[0] == s[len - 1]){
		return palindrome(s.substr(1, len - 2));
	}else{
		return false;
	}
}
