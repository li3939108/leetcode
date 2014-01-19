#include <iostream>
#include <string>
#include <map>

using namespace std;

bool isInterleave(string s1, string s2, string s3) {
	int i ;
	if(s1.length() + s2.length() != s3.length()){
		return false ;
	}
	if(s1.length() == 0 && s2.length() == 0){
		return s3.length() == 0 ;
	}else if(s1.length() == 0){
		return ! s3.compare(s2) ;
	}else if(s2.length() == 0){
		return ! s3.compare(s1) ;
	}else{
		if(s3[0] == s2[0] && s3[0] == s1[0]) {
			int len1 = s1.length() - 1 ;
			int len2 = s2.length() ;
			return	isInterleave(s1.substr(1, len1), s2, s3.substr(1, s3.length() - 1)) || 
					isInterleave(s1, s2.substr(1, s2.length() - 1), s3.substr(1, s3.length() - 1)) ;
		}else if(s3[0] == s2[0]){
			return isInterleave(s1, s2.substr(1, s2.length() - 1), s3.substr(1, s3.length() - 1)) ;
		}else if(s3[0] == s1[0]){
			return isInterleave(s1.substr(1, s1.length() - 1), s2, s3.substr(1, s3.length() - 1)) ;
		}else{
			return false ;
		}

	}
	
}
int main(){
	string s1("bbbbbabbbbabaababaaaabbababbaaabbabbaaabaaaaababbbababbbbbabbbbababbabaabababbbaabababababbbaaababaa") ;
	string s2("babaaaabbababbbabbbbaabaabbaabbbbaabaaabaababaaaabaaabbaaabaaaabaabaabbbbbbbbbbbabaaabbababbabbabaab") ;
	string s3("babbbabbbaaabbababbbbababaabbabaabaaabbbbabbbaaabbbaaaaabbbbaabbaaabababbaaaaaabababbababaababbababbbababbbbaaaabaabbabbaaaaabbabbaaaabbbaabaaabaababaababbaaabbbbbabbbbaabbabaabbbbabaaabbababbabbabbab") ;

	cout << "result: " << ' ' << isInterleave(s1, s2, s3) << '\n';
}