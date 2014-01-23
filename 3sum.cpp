#include <iostream>
#include <vector>
#include <map>

using namespace std;
vector<int> twoSum(vector<int> &numbers, int target) {
    vector<int> mul(numbers.size() , 0);
    vector<int> ans(2 , 0);
    map<int,int> mapping;
    int i, i2;
    for (i=0; i<numbers.size(); ++i)
    {
       mapping[numbers[i]] = i + 1 ;
    }
    for(i = 0; i< numbers.size(); i++){
        i2 = mapping[target - numbers[i] ];
        if(i2 > 0 && i + 1 != i2){
            ans[0] = i + 1;
            ans[1] = mapping[target - numbers[i]];
            break ;
        }
    }

    return ans;
}
vector<vector<int> > threeSum(vector<int> &num) {
	map<int, int> m ;
	int s = num.size();
	int i, j;
	for(i = 0; i < s; i++){
		
	}

}
