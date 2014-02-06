/*
Given a string, find the length of the longest substring without repeating characters. For example, the longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3. For "bbbbb" the longest substring is "b", with the length of 1.
*/
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int lengthOfLongestSubstring(string s) {
    map<char, int> m ;
    vector<int> l(s.length(), 0);
    vector<int>::iterator iter ;
    int i , j, k=0, max = 0;
    for(i = 0; i< s.length(); i++){
        int tmsi;
        l[i] = l.size() - i ;
        if((tmsi = m[s[i]]) > 0){
            for(j = tmsi - 1; j >= k; j--){
                int tmp = i  -tmsi + tmsi - j;
                if(l[j] > tmp){
                    l[j] = tmp ;   
                }
            }
            k = tmsi ;//make it O(n)  
        }
        m[s[i]] = i + 1 ;
    }
    for(iter = l.begin(); iter != l.end(); iter++){
        if(*iter > max){
            max = *iter ;
        }
    }
    return max;
}
int main(){
    string s = "fpdcztbudxfipowpnamsrfgexjlbjrfoglthewbhtiriznzmolehqnlpwxrfowwwjrd";
    cout << "length: " << lengthOfLongestSubstring(s) << '\n';
}
