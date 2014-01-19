#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>

using namespace std;

string minWindow(string S, string T) {
	unordered_set<char> charset(T.begin(), T.end()) ;
	unordered_map<char, int> cnt ;
	unordered_map<char, int> n ;
	int i = 0,j = 0, count = 0, Tlen = T.length(), Slen = S.length();
	string min("") ;
	for(i = 0; i < T.length(); i++){
		n[T[i]] += 1 ;
	}
	i = 0; j = 0;
	while(j < Slen){
		if(charset.find(S[j] ) != charset.end() ){
			string sub ;
			cnt[S[j]] += 1;
			count += (cnt[S[j]] <= n[S[j]] ? 1 : 0) ;
			if(count == Tlen){
				while(1){
					cnt[S[i]] -= 1 ;
					if(cnt[S[i]] < n[S[i]] && cnt[S[i]] >= 0){
						count -= 1;
						break ;
					}
					i++;
				}
				sub =  S.substr(i, j - i + 1) ;
				if(min.length() == 0){
					min.assign(sub );
				}else{
					if(min.length() > j - i + 1){
						min.assign(sub );
					}
				}
				i++;
			}
		}
		j ++ ;
	}
	return min ;
}
int main(){
	string S("A") ;
	string T("AA") ;
	cout << "result:\n" << minWindow(S, T) << '\n' ;
	return 0 ;

}
