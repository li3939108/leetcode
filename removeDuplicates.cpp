#include <iostream>
#include <cstring>

using namespace std;

int removeDuplicates(int A[], int n) {
    int i=0, nn = n;
    while(i +1<nn){
        if(A[i] == A[i+1]){
            memmove(A + i, A + i + 1, (nn - 1 -i) * sizeof(int) );
            nn --;
        }else{
            i++;
        }
    }
    return nn;
}
int main(){
    int test[] = {-1, 2, 2, 2, 3, 4, 5 ,6 , 7 ,7 };
    int i, nn;
    cout << "testcase:" ;
    for(i=0;i < sizeof(test) / sizeof(int);i++){
        cout << ' '<< test[i] ;
    }
    cout << '\n' ;
    nn = removeDuplicates(test, sizeof(test) / sizeof(int)) ;
    cout << "result:" << nn << "  " ;
    for(i = 0; i < nn; i++){
        cout << ' ' << test[i] ;
    }
    cout << '\n' ;
}