#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > permute(vector<int> &num) {
    if(num.size() == 2){
        vector<int> n1 (num), n2(0);
        vector<vector<int> > r (2);
        vector<int> n1_copy (n1);
        n2.push_back(n1_copy.back());n1_copy.pop_back();
        n2.push_back(n1_copy.back());n1_copy.pop_back();
        r[0] = n1 ;
        r[1] = n2 ;
        return r ;
    }else if(num.size() == 1){
        vector<vector<int> > r(1, num);
        return r;
    }else if(num.size() == 0){
        vector<vector<int> > r(0);
        r.clear();
        return r;
    }else{
        vector<vector<int> > r(0);
        vector<int> n1(num);
        vector<int>::iterator iter;
        vector<vector<int> >::iterator iter1 ;
        for(iter = n1.begin(); iter != n1.end() ; iter ++){
            vector<int> n1_copy (n1);
            vector<vector<int> > rp ;
            n1_copy.erase(n1_copy.begin() + (iter - n1.begin()));
            rp = permute(n1_copy) ;
            for(iter1 = rp.begin(); iter1 != rp.end(); iter1 ++){
                (*iter1).push_back(*iter);
            }
            r.insert(r.end(), rp.begin(), rp.end());
        }
        return r;
    }
}
int main(int argc , char ** argv){
	vector<int> t(5, 0) ;
	vector<vector<int> > r ;
    int i, j ;
	t[0] = 1; t[1] = 2; t[2] =5 ; t[3] = 8;
	r = permute(t) ;
    for(i = 0; i< r.size(); i++){
        cout << "r[" << i << "]:";
        for(j = 0; j< r[0].size(); j ++){
            cout << ' ' << r[i][j]  ;
        }
        cout << '\n' ;
    }
}